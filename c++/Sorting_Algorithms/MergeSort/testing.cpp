// C++ program to check the nature of the roots

#include <bits/stdc++.h>
using namespace std;

// BVA for nature of roots of a quadratic equation
void nature_of_roots(int a, int b, int c)
{

	// If a = 0, D/2a will yield exception
	// Hence it is not a valid Quadratic Equation
	if (a == 0) {
		cout << "Not a Quadratic Equation"
			<< endl;
		return;
	}

	int D = b * b - 4 * a * c;

	// If D > 0, it will be Real Roots
	if (D > 0) {
		cout << "Real Roots" << endl;
	}

	// If D == 0, it will be Equal Roots
	else if (D == 0) {
		cout << "Equal Roots" << endl;
	}

	// If D < 0, it will be Imaginary Roots
	else {
		cout << "Imaginary Roots" << endl;
	}
}


// Driver Code
int main()
{

    int a, b, c,n=13;
	cout << "Testcase"<<endl;
    
    for(int i=0; i<n; i++){
        cout<<"enter a, b and c: ";
        cin>>a>>b>>c;
        nature_of_roots(a,b,c);
}
return 0;
}
