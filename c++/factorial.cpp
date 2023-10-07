#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;

}

int nCr(int n, int r){
    int num = factorial(n);

    int denom = factorial(r) * factorial(n - r);

    return num/denom;
}
int main()
{
    int n,r;

    cout << "Enter the value of n : " << endl;
    cin >> n;

    cout << "Enter the value of r : " << endl;
    cin >> r;

    cout << " Answer is : " << nCr(n, r) << endl;
    return 0;
}
