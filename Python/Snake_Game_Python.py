#!/usr/bin/env python3

import curses
import random
import argparse
import os

CHARACTER_ASPECT_RATIO = 19 / 9
FILENAME = os.path.expanduser("~/.config/snake-best-score.txt")


class SnakeBoardDescriptor:
    def __init__(
        self, rows, cols, char_snake, char_head, char_food, char_bg, max_speed
    ):
        self.rows = rows
        self.cols = cols
        self.char_snake = char_snake
        self.char_head = char_head
        self.char_food = char_food
        self.char_bg = char_bg
        self.is_large_enough = self.cols > 50
        self.max_speed = max_speed


def get_args():
    parser = argparse.ArgumentParser(description="snake game", add_help=False)
    parser.add_argument(
        "--help", "-h", action="help", help="show this help message and exit"
    )
    parser.add_argument("--cheat", type=int, help=argparse.SUPPRESS)
    parser.add_argument(
        "--black-white",
        "--bw",
        action="store_true",
        help="disable colors (black and white only)",
    )
    parser.add_argument("--rows", "-r", type=int, help="set rows")
    parser.add_argument("--columns", "-c", type=int, help="set columns")
    parser.add_argument(
        "--color-snake",
        choices=["black", "white", "red", "green", "yellow", "blue", "magenta", "cyan"],
        default="green",
        help="set snake color",
    )
    parser.add_argument(
        "--color-food",
        choices=["black", "white", "red", "green", "yellow", "blue", "magenta", "cyan"],
        default="yellow",
        help="set food color",
    )
    parser.add_argument(
        "--color-bg",
        choices=["black", "white", "red", "green", "yellow", "blue", "magenta", "cyan"],
        default="white",
        help="set background color",
    )
    parser.add_argument(
        "--char-snake", type=str, default="#", help="set snake character"
    )
    parser.add_argument("--char-head", type=str, default="#", help="set head character")
    parser.add_argument("--char-food", type=str, default="*", help="set food character")
    parser.add_argument(
        "--char-bg", type=str, default=".", help="set background character"
    )
    parser.add_argument("--speed", "-s", type=int, default=10, help="set speed")
    return parser.parse_args()


def end(stdscr, exit_msg, **kwargs):
    try:
        curses.nocbreak()
        stdscr.keypad(False)
        curses.echo()
        curses.endwin()
    except curses.error:
        return "Error in exiting"
    return (
        exit_msg
        + "\n"
        + ", ".join(
            f"{k.capitalize().replace('_', ' ')}: {v}" for k, v in kwargs.items()
        )
    )

# ... (continued in the next response)

def update_best_score(score, best_score=None):
    best_score = best_score if best_score else fetch_best_score(score)
    if score > best_score:
        with open(FILENAME, "w") as f:
            f.write(str(score))
    return max(score, best_score)


def fetch_best_score(score=0):
    if not os.path.exists(FILENAME):
        with open(FILENAME, "w") as f:
            f.write(str(score))
        return score
    with open(FILENAME, "r") as f:
        return int(f.read().split("\n")[0])


def main(args: argparse.Namespace):
    stdscr = curses.initscr()
    curses.start_color()
    curses.cbreak()
    curses.curs_set(0)
    curses.use_default_colors()
    curses.noecho()
    stdscr.nodelay(True)
    stdscr.timeout(1000 // args.speed)
    stdscr.keypad(1)

    colors = {
        "black": curses.COLOR_BLACK,
        "white": curses.COLOR_WHITE,
        "red": curses.COLOR_RED,
        "green": curses.COLOR_GREEN,
        "yellow": curses.COLOR_YELLOW,
        "blue": curses.COLOR_BLUE,
        "magenta": curses.COLOR_MAGENTA,
        "cyan": curses.COLOR_CYAN,
    }

    curses.init_pair(1, -1 if args.black_white else colors[args.color_bg], -1)
    curses.init_pair(2, -1 if args.black_white else colors[args.color_snake], -1)
    curses.init_pair(3, -1 if args.black_white else colors[args.color_food], -1)

    params = SnakeBoardDescriptor(
        args.rows or stdscr.getmaxyx()[0] - 1,
        args.columns or stdscr.getmaxyx()[1] - 1,
        args.char_snake,
        args.char_head,
        args.char_food,
        args.char_bg,
        args.speed,
    )

    snake = [[5, 5], [5, 4], [5, 3]]
    paused = False
    direction = 100
    body = [*snake[0]]
    food = [params.rows // 2, params.cols // 2]
    if args.cheat:
        for i in range(args.cheat):
            snake.append([5, 3])
    score = len(snake)
    best_score = update_best_score(score)

    for x in range(params.rows):
        for y in range(params.cols):
            stdscr.addstr(x, y, params.char_bg, curses.color_pair(1))

    for i, _ in enumerate(snake):
        stdscr.addstr(*snake[i], params.char_head, curses.color_pair(2))

    stdscr.addstr(
        params.rows // 2, params.cols // 2, params.char_food, curses.color_pair(3)
    )

    stdscr.addstr(
        params.rows,
        0,
        "Controls: wasd or arrow keys, q to quit | Score: 0"
        if params.is_large_enough
        else "Score: 0",
        curses.color_pair(1),
    )

    while True:
        try:
            next_direction = stdscr.getch()
        except KeyboardInterrupt:  # exit on ^C
            return end(stdscr, "Quit", score=score, best_score=best_score)
        direction = direction if next_direction == -1 else next_direction
        new_head = snake[0].copy()
        if direction in (119, 259):  # w | ^
            new_head[0] -= 1
            stdscr.timeout(int(1000 / (params.max_speed / CHARACTER_ASPECT_RATIO)))
        elif direction in (97, 260):  # a | <
            new_head[1] -= 1
            stdscr.timeout(1000 // params.max_speed)
        elif direction in (115, 258):  # s | v
            new_head[0] += 1
            stdscr.timeout(int(1000 / (params.max_speed / CHARACTER_ASPECT_RATIO)))
        elif direction in (100, 261):  # d | >
            new_head[1] += 1
            stdscr.timeout(1000 // params.max_speed)
        elif direction in (113, 27):  # q | esc
            return end(stdscr, "Quit", score=score, best_score=best_score)
        else:
            continue
        if not paused:
            snake.insert(0, new_head)
            if snake[0][0] in (params.rows, -1):
                return end(
                    stdscr,
                    "Snake out of bounds vertically",
                    score=score,
                    best_score=best_score,
                )
            if snake[0][1] in (params.cols, -1):
                return end(
                    stdscr,
                    "Snake out of bounds horizontally",
                    score=score,
                    best_score=best_score,
                )
            if snake[0] in snake[1:]:
                return end(
                    stdscr, "Snake can't eat itself", score=score, best_score=best_score
                )
            if snake[0] == food:
                food = None
                while food is None:
                    new_food = [
                        random.randint(0, params.rows - 1),
                        random.randint(0, params.cols - 1),
                    ]
                    food = new_food if new_food not in snake else None
                stdscr.addstr(*food, params.char_food, curses.color_pair(3))
                score += 1
                best_score = update_best_score(score)
            else:
                stdscr.addstr(*snake.pop(-1), params.char_bg, curses.color_pair(1))
            stdscr.addstr(*body, params.char_snake, curses.color_pair(2))
            body = [*snake[0]]
            stdscr.addstr(*snake[0], params.char_head, curses.color_pair(2))
        stdscr.addstr(
            params.rows,
            49 if params.is_large_enough else 7,
            str(score),
            curses.color_pair(1),
        )
        stdscr.refresh()


if __name__ == "__main__":
    print(f"Game over: {main(get_args())}")