color_list = [(192, 165, 115), (138, 166, 190), (56, 102, 140), (141, 91, 50), (12, 23, 55), (222, 207, 123), (182, 154, 42), (61, 22, 11), (182, 146, 165), (142, 177, 151), (72, 117, 81), (58, 15, 26), (126, 79, 102), (130, 30, 16), (15, 39, 23), (24, 53, 127), (177, 188, 215), (164, 104, 134), (115, 31, 46), (97, 150, 100), (98, 121, 172), (210, 178, 197), (174, 105, 93), (74, 150, 165), (25, 91, 65), (172, 205, 180), (86, 76, 17), (216, 181, 175), (163, 203, 213), (18, 86, 100), (231, 205, 16)]
import turtle as t
from random import choice
tim = t.Turtle()
tim.speed("fastest")
tim.hideturtle()
tim.penup()
tim.setheading(225)
t.colormode(255)
tim.forward(300)
tim.setheading(0)
number_of_dots = 100

for dots in range(1, number_of_dots + 1):
    tim.dot(20, choice(color_list))
    tim.forward(50)
    if (dots % 10 == 0):
        tim.setheading(90)
        tim.forward(50)
        tim.setheading(180)
        tim.forward(500)
        tim.setheading(0)
        
screen = t.Screen()
screen.exitonclick()
