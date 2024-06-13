#include <iostream>
using namespace std;

/**
 * This function prints the steps to solve the Tower of Hanoi problem.
 * 
 * @param n_disc The number of disks to be moved.
 * @param A The source tower.
 * @param C The destination tower.
 * @param B The auxiliary tower.
 */

void Hanoi(int n_disc, char A, char C, char B) {
    if (n_disc == 1) {
        cout << "Move disk from " << A << " to " << C << endl;
    } else {
        Hanoi(n_disc - 1, A, B, C);
        cout << "Move disk from " << A << " to " << C << endl;
        Hanoi(n_disc - 1, B, C, A);
    }
}

int main() {
    int n_disc;
    cout << "Enter the number of disks: ";
    cin >> n_disc;
    Hanoi(n_disc, 'A', 'C', 'B');
    return 0;
}

/* The Tower of Hanoi is a mathematical puzzle that consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
No disk may be placed on top of a smaller disk.
The function Hanoi takes four arguments:

n_disc - the number of disks to be moved
A - the starting rod
C - the destination rod
B - the auxiliary rod
The function first checks if there is only one disk to be moved. If so, it simply prints the move from the starting rod to the destination rod. If there are more than one disk, it recursively calls the Hanoi function with n_disc-1 disks, moving them from the starting rod to the auxiliary rod. Then it prints the move of the remaining disk from the starting rod to the destination rod. Finally, it recursively calls the Hanoi function with n_disc-1 disks, moving them from the auxiliary rod to the destination rod.

The main function simply takes the input of the number of disks to be moved and calls the Hanoi function with the starting rod as A, the destination rod as C, and the auxiliary rod as B. */
