/*This C++ program showcases methods for generating the Fibonacci sequence,
 using both recursive and iterative approaches,
providing users the flexibility to choose their preferred method for calculating the sequence.*/

#include <iostream>

// Recursive approach to calculate Fibonacci sequence
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative approach to calculate Fibonacci sequence
void fibonacciIterative(int n) {
    int first = 0, second = 1, next;

    std::cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        std::cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
}

int main() {
    int n;

    std::cout << "Enter the number of terms for the Fibonacci sequence: ";
    std::cin >> n;

    std::cout << "Fibonacci sequence using recursive approach:\n";
    for (int i = 0; i < n; ++i)
        std::cout << fibonacciRecursive(i) << " ";

    std::cout << "\n\n";

    std::cout << "Fibonacci sequence using iterative approach:\n";
    fibonacciIterative(n);

    std::cout << "\n";

    return 0;
}