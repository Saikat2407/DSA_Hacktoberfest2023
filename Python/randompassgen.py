import string
import random

def generate_password(length):
    # define the character sets for password generation
    uppercase_letters = string.ascii_uppercase
    lowercase_letters = string.ascii_lowercase
    digits = string.digits
    special_characters = string.punctuation

    # combine all character sets to create the full set of characters for password generation
    all_characters = uppercase_letters + lowercase_letters + digits + special_characters

    # generate a password of a specified length
    password = ''.join(random.choice(all_characters) for i in range(length))

    return password

# generate a password of length 12
num = int(input("Enter the length of password: "))
password = generate_password(num)

print(f"Your generated password is: {password}")