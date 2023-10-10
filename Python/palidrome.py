def is_palindrome(word):
    """Check if the given word is a palindrome."""
    # Convert the word to lowercase and remove non-alphanumeric characters
    word = ''.join(c for c in word.lower() if c.isalnum())
    # Check if the word reads the same forwards and backwards
    return word == word[::-1]

# Get input from user
word = input("Enter a word: ")

# Check if input is a palindrome
if is_palindrome(word):
    print(f"{word} is a palindrome!")
else:
    print(f"{word} is not a palindrome.")