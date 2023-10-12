/*
   Codeforces Round 145(Rated for div. 2)
   Problem B - Points on Plane
   Problem link - https://codeforces.com/contest/1809/problem/B
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
    ll n;
    cin >> n;
    ll l = -1;
    ll r = 1e9;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    cout << r - 1 << "\n";
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