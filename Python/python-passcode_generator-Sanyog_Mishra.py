#Password Generator Project
import random

letters = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
]
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("------GenZ Password Generator!------")
nl = int(input("\nHow many letters would you like in your password?: "))
ns = int(input("How many symbols would you like?: "))
nn = int(input("How many numbers would you like?: "))

list_p = list(range(nl + ns + nn))
for n in range(nl):
    a = random.randint(0, len(letters) - 1)
    list_p[n] = letters[a]

for n in range(ns):
    a = random.randint(0, len(symbols) - 1)
    list_p[nl + n] = symbols[a]

for n in range(nn):
    a = random.randint(0, len(numbers) - 1)
    list_p[nl + ns + n] = numbers[a]

random.shuffle(list_p)

passcode=''
for n in range(len(list_p)):
    passcode = passcode + list_p[n]

print(f"Your password: {passcode}")
