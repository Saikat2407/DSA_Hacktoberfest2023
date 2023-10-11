/* 
   Codeforces Round 145(Rated for div. 2)
   Problem C - Sum on Subarrays
   Problem link - https://codeforces.com/contest/1809/problem/C
*/

#include <bits/stdc++.h>
#define amz fourrr
#define ll long long
#define vll vector<ll>
using namespace std;
const ll M = 1e9 + 7;
const ll NUM = 1e18;

void fsolve()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (k >= i)
        {
            cout << "2 ";
            k -= i;
        }
        else if (k)
        {
            cout << -2 * (i - k) + 1 << " ";
            k = 0;
        }
        else
            cout << "-1000 ";
    }
    cout << "\n";
}

int main()
{
    ll t;
    t = 1;
    cin >> t;
    while (t--)
    {
        fsolve();
    }
    return 0;
}