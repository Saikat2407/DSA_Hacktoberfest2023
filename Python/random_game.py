import random
class ValueTooLarge(Exception):
    def display(self):
        print("Value larger than correct value")
class ValueTooSmall(Exception):
    def display(self):
        print("Value smaller than correct value")
x=random.randrange(1,11,1)
y=1
if x<=5:
    print("Unlucky... You only have ",x," trys. Good luck")
else:
    print("Lets go! You have ",x," trys. Good luck")
a=random.randrange(1,100,1)
b=int(input("Enter your guess:"))
while a!=b:
    y+=1
    try:
        
        if a<=b:
            raise ValueTooLarge
        else:
            raise ValueTooSmall
    except ValueTooSmall as e:
        e.display()
    except ValueTooLarge as l:
        l.display()
    b=int(input("Enter another number:"))
    if y>=x:
        if a!=b:
         print("You're out of trys.. Better luck next time.")
         print("The correct number was:",a)
         break
    if a==b:
        print("You guessed correctly!!CONGRATS")
