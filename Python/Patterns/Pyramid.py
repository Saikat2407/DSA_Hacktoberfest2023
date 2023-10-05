# Function to print a star pyramid
def print_star_pyramid(n):
    for i in range(1, n + 1):
        # Print spaces
        for j in range(n - i):
            print(" ", end="")
        # Print stars
        for k in range(2 * i - 1):
            print("*", end="")
        print()

# Input the number of rows for the pyramid
n = int(input("Enter the number of rows: "))

# Call the function to print the pyramid
print_star_pyramid(n)
