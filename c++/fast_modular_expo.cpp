#include <iostream>

int function(int a, int b, int n) {
    if (b == 1) {
        return a % n;
    }
    if (b % 2 == 0) {
        return (function(a, b / 2, n) * function(a, b / 2, n)) % n;
    } else {
        return (function(a, b / 2, n) * function(a, b / 2, n) * a) % n;
    }
}

int bruteForceModExp(int a, int b, int n) {
    int result = 1;

    for (int i = 0; i < b; i++) {
        result = (result * a) % n;
    }

    return result;
}

int main() {
    std::cout << "Enter base: ";
    int a;
    std::cin >> a;
    std::cout << "Enter exponent: ";
    int b;
    std::cin >> b;
    std::cout << "Enter the modulo number: ";
    int n;
    std::cin >> n;
    std::cout << bruteForceModExp(a, b, n);

    return 0;
}
