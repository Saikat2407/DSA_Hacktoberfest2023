def fibonacci(n):
    """Return the nth Fibonacci number."""
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == "__main__":
    # Get the first n Fibonacci numbers
    n = int(input("Enter a number: "))
    for i in range(n):
        print(fibonacci(i))