#include <iostream>
using namespace std;
void TowerOfHanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    TowerOfHanoi(n - 1, source, dest, aux);
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    TowerOfHanoi(n - 1, aux, source, dest);
}
int main() {
    int NumDisks = 3;
    char source = 'A';
    char aux = 'B';
    char dest = 'C';
    cout << "Tower of Hanoi solution with " << NumDisks << " disks:" << endl;
    TowerOfHanoi(NumDisks, source, aux, dest);
    return 0;
}
