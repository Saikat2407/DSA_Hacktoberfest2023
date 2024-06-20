import random

# Daftar kata yang dapat dipilih
word_list = ["python", "programming", "developer", "computer", "keyboard", "algorithm", "variable"]

# Fungsi untuk memilih kata secara acak
def choose_word():
    return random.choice(word_list)

# Fungsi untuk menjalankan permainan
def play_game():
    secret_word = choose_word()
    guessed_letters = []
    attempts = 6  # Jumlah percobaan yang diberikan kepada pemain

    print("Welcome to the Word Guessing Game!")
    print("I've selected a random word. Try to guess it!")

    while attempts > 0:
        display_word = ""
        for letter in secret_word:
            if letter in guessed_letters:
                display_word += letter
            else:
                display_word += "_ "

        print(display_word)
        print(f"Attempts left: {attempts}")

        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You already guessed that letter.")
            continue

        guessed_letters.append(guess)

        if guess in secret_word:
            print("Good guess!")
        else:
            print("Incorrect guess.")
            attempts -= 1

        if set(secret_word) == set(guessed_letters):
            print("Congratulations! You guessed the word:", secret_word)
            break

    if attempts == 0:
        print("You're out of attempts. The word was:", secret_word)

if __name__ == "__main__":
    play_game()
