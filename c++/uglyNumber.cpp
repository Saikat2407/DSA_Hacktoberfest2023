// C++ program to find nth ugly number
//so Ugly numbers are positive integers that have only prime factors 2, 3, or 5. Here's a C++ program to find the nth ugly number:
//Here is c++ code

#include <iostream>
#include <vector>
using namespace std;

int getNthUglyNumber(int n) {
    vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1; // The first ugly number is 1

    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 1; i < n; i++) {
        int nextUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUgly;

        if (nextUgly == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUgly == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUgly == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }

    return uglyNumbers[n - 1];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ugly = getNthUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << ugly << endl;

    return 0;
}
