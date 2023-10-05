#include <iostream>

// Function to move a disk from source peg to destination peg
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    // Move n-1 disks from source to auxiliary peg using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination peg
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;

    // Move the n-1 disks from auxiliary peg to destination peg using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3; // Change this to the number of disks you want to solve for
    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    std::cout << "Tower of Hanoi solution with " << numDisks << " disks:" << std::endl;
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
