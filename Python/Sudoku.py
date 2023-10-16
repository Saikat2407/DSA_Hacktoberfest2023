Skip to content
Create Sudoku Game In Python [source code included]
FREE Online Courses: Dive into Knowledge for Free. Learn More!

Sudoku is one of the most popular games, it is a fun game that keeps the brain active.

We have a 9×9 grid in sudoku, in which every row and column should have elements from 1 to 9 without repetition, also every 3×3 grid from the left most cell should follow this rule.

We will use Pygame to develop sudoku game in python.

Pygame: Pygame is a python library which provides geometry functions for drawing lines, rectangles, and many more shapes very easily. It helps in multimedia application development.


Sudoku Game Prerequisites
We just need pygame for this sudoku python project, below is the command to install:

pip install pygame
Download Sudoku Python Code
Please download the source code of python sudoku game: Sudoku Python Code

Create Sudoku Python Files
1. main.py
import pygame
#for making get calls to access sugoku url 
import requests
 
#making get request to the api, you can change the difficulty level in the url
resp = requests.get("https://sugoku.herokuapp.com/board?difficulty=easy")
 
#fetching grid from the response
board =  resp.json()['board']
 
#making a copy of the board beacuse we will be changing the values of the board
#  so at last it will help in checking the correctness
original = [[board[i][j] for j in range(len(board[0]))] for i in range(len(board))]
 
bg_color = (250,245,243)
black = (0,0,0)
 
def place(window,pos):
    Board_font = pygame.font.SysFont('Arial',30)
    x,y = pos[1], pos[0]
 
    while True:
        for e in pygame.event.get():
            #if user has pressed quit button, quit the window
            if (e.type == pygame.QUIT):
                pygame.quit()
                return
 
            # if user wants to enter a value
            if e.type == pygame.KEYDOWN:
                #case 1: trying to modify original value
                if original[x-1][y-1]!=0: # since the blank values are zeros
                    return
                
                #case 2: Trying to edit previously entered digit
                # 0 is mapped to 48 in ascii nomenclature so here we are checking with 0
                if (e.key == 48): 
                    #erasing previosly entered value in backend
                    board[x-1][y-1] = e.key-48
                    #erasing previosly entered value on the screen
                    pygame.draw.rect(window, bg_color, (y*50+5, x*50+5, 50-10,50-10) )
 
                    #again displaying updated window
                    pygame.display.update()
                    return
                
                #case 3: Trying to enter a value in a blank cell
                if(0< e.key-48 < 10): #valid input
                    #erasing previosly entered value on the screen
                    pygame.draw.rect(window, bg_color, (y*50+5, x*50+5, 50-10,50-10) )
                    
                    val=Board_font.render(str(e.key-48), True, black)
                    window.blit(val, (y*50 + 15,  x*50 + 5) )
 
                    board[x-1][y-1]= e.key-48
 
                    #again displaying updated window
                    pygame.display.update()
                    return
               
                    
def game():
    #initializing pygame
    pygame.init()
 
    #setting pygame window size 550x550
    window = pygame.display.set_mode((550,550))
 
    #setting the caption
    pygame.display.set_caption('ProjectGurukul Sudoku')
 
    #filling background color
    window.fill(bg_color)
 
    #declaring the font
    Board_font = pygame.font.SysFont('Arial',30)
 
    #creating grid
    # we need 10 horizontal and 10 vertical lines
    for i in range(0,10):
        if i%3==0:
            #every third line is bold, therefore changing the width to 4
            pygame.draw.line(window, black, (50+50*i,50), (50+50*i,500) , 4)
            pygame.draw.line(window, black, (50,50+50*i), (500,50+50*i) , 4)
    
        else:
            # draw.line(window, color, start coodinate, end coodinate, width)
            #vertical lines
            pygame.draw.line(window, black, (50+50*i,50), (50+50*i,500) , 2)
            #horizontal lines
            pygame.draw.line(window, black, (50,50+50*i), (500,50+50*i) , 2)
    
    #placing elements on the board
    for x in range(0,len(board[0])):
        for y in range(0,len(board[0])):
 
            #if it is a number between 1 to 9
            if(board[x][y]>0 and board[x][y]<10):
 
                #rendering the text
                val = Board_font.render(str(board[x][y]), True , (100,100,200) )
                #blitting the text on the board
                window.blit(val,((y+1)*50 + 15,  (x+1)*50 + 5 ))
 
    #again displaying updated window
    pygame.display.update()
 
    while True:
        for e in pygame.event.get():
 
            #left click
            if e.type == pygame.MOUSEBUTTONUP and e.button == 1:
                # to get the position of the cell we are storing the mouse position in coordinates variable
                coordinates = pygame.mouse.get_pos()
                # dividing by 50 because we have taken every cell to be of 50x50 dimension
                place(window, (coordinates[0]//50,coordinates[1]//50))
            
            #if user has pressed quit button, quit the window
            if (e.type == pygame.QUIT):
                pygame.quit()
                return
 
#calling game method
game()
We are using sugoku api to create the initial board values. And to use the same we are importing the request module and then we are making a get request and storing the grid values in our board.

Python Sudoku Game Output
python sudoku output

playing sudoku


2. solver.py
import pygame
#for making get calls to access sugoku url 
import requests
 
#making get request to the api, you can change the difficulty level in the url
resp = requests.get("https://sugoku.herokuapp.com/board?difficulty=easy")
 
#fetching grid from the response
board =  resp.json()['board']
 
#making a copy of the board beacuse we will be changing the values of the board
#  so at last it will help in checking the correctness
original = [[board[i][j] for j in range(len(board[0]))] for i in range(len(board))]
 
bg_color = (250,245,243)
black = (0,0,0)
 
# this function return true if we can place the val at pos in the grid 
def valid(pos, val):
 
    #checking in it's row
    for x in range(0,9):
        if board[pos[0]][x] == val:
            return False
        
    #checking in it's column
    for x in range(0,9):
        if board[x][pos[1]] == val:
            return False
 
    #checking in 3x3 box
    i = pos[0]//3*3
    j = pos[1]//3*3
        
    for x in range(0,3):
        for y in range(0,3):
            if board[x+i][y+j] == val:
                return False
    
    return True
 
# return true if the val is zero
def empty(val):
    #board value will be zero if the cell is empty
    if val==0:
        return True
    else:
        return False
 
complete = 0
 
#solves the sudoku using backtracking
def solve(window):
    global complete
    #declaring the font
    Board_font = pygame.font.SysFont('Arial',30)
 
    for x in range(0,9):
        for y in range(0,9):
 
            #if current cell is empty
            if(empty(board[x][y])):
 
                #trying all possible values[1,9] for cell[x][y]
                for val in range(1,10):
                    # checking if we can place val at cell[x][y] 
                    if( valid( (x,y) ,val) ):
                        board[x][y]=val
                        pygame.draw.rect(window, bg_color, ((y+1)*50+5, (1+x)*50+5, 50-10,50-10) )
 
                        #placing val at board[x][y]
                        value=Board_font.render(str(val), True, black)
                        window.blit(value, ((1+y)*50 + 15, (1+x)*50 + 5) )
 
                        #again displaying updated window
                        pygame.display.update()
 
                        #delaying time so that we can see the output 
                        pygame.time.delay(15)
 
                        #again calling solve() to fill rest of the cells
                        solve(window)
                        if complete == 1:
                            return
 
                        board[x][y]=0
                        #erasing previosly entered value on the screen
                        pygame.draw.rect(window, bg_color, (y*50+5, x*50+5, 50-10,50-10) )
 
                        #again displaying updated window
                        pygame.display.update()
                return
    complete=1
                    
 
def game():
    #initializing pygame
    pygame.init()
 
    #setting pygame window size 550x550
    window = pygame.display.set_mode((550,550))
 
    #setting the caption
    pygame.display.set_caption('ProjectGurukul Sudoku Solver')
 
    #filling background color
    window.fill(bg_color)
 
    #declaring the font
    Board_font = pygame.font.SysFont('Arial',30)
 
    #creating grid
    # we need 10 horizontal and 10 vertical lines
    for i in range(0,10):
        if i%3==0:
            #every third line is bold, therefore changing the width to 4
            pygame.draw.line(window, black, (50+50*i,50), (50+50*i,500) , 4)
            pygame.draw.line(window, black, (50,50+50*i), (500,50+50*i) , 4)
    
        else:
            # draw.line(window, color, start coodinate, end coodinate, width)
            #vertical lines
            pygame.draw.line(window, black, (50+50*i,50), (50+50*i,500) , 2)
            #horizontal lines
            pygame.draw.line(window, black, (50,50+50*i), (500,50+50*i) , 2)
    
    #placing elements on the board
    for x in range(0,len(board[0])):
        for y in range(0,len(board[0])):
 
            #if it is a number between 1 to 9
            if(board[x][y]>0 and board[x][y]<10):
 
                #rendering the text
                val = Board_font.render(str(board[x][y]), True , (100,100,200) )
                #blitting the text on the board
                window.blit(val,((y+1)*50 + 15,  (x+1)*50 + 5 ))
 
    #again displaying updated window
    pygame.display.update()
 
    solve(window)
    while True:
        for e in pygame.event.get():
            
            #if user has pressed quit button, quit the window
            if (e.type == pygame.QUIT):
                pygame.quit()
                return
 
#calling game method
game()
 
