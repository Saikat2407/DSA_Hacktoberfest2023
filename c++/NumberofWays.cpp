// Solution of Codeforces problem 466 C Number of Ways https://codeforces.com/contest/466/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define M 1
// tc fori forj
// 1 sec -10^8
// max len of arr -10^7
// max len of vector 2147483648 < 10^10
// for loops not more that 10^5
// QUALITY>QUANTITY
//  NO WRONG SUBMISSIONS ONLY CORRECT ANSWERS
//-------------------------------------------------------------------------------------------------------------------------------
//
// FIRST YOU SHOULD GET THE LOGIC CORRECTLY , READ THE QUESTION CORRECTLY
//
//-------------------------------------------------------------------------------------------------------------------------------
//===============================================vignesh========================================================================

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        sum += b;
        arr[i] = b;
    }
    if (sum % 3 == 0)
    {
        for (ll i = 1; i < n; i++)
        {
            arr[i] = arr[i] + arr[i - 1];
        }

        if (sum == 0)
        {
            ll third[n] = {0};
            ll twothird[n] = {0};

            for (ll i = 0; i < n; i++)
            {
                if (arr[i] == sum / 3)
                {
                    third[i]++;
                }
                if (arr[i] == 2 * sum / 3)
                {
                    twothird[i]++;
                }
            }

            for (ll i = n - 2; i > 0; i--)
            {
                twothird[i - 1] += twothird[i];
            }

            ll ans = 0;
            for (ll i = 0; i < n; i++)
            {
                if (third[i] == 1)
                {
                    ans += (twothird[i]-1);
                }
            }
            cout << ans << "\n";
        }
        else
        {
            // for (auto x : arr)
            // {
            //     cout << x << " ";
            // }

            ll third[n] = {0};
            ll twothird[n] = {0};

            for (ll i = 0; i < n; i++)
            {
                if (arr[i] == sum / 3)
                {
                    third[i]++;
                }
                if (arr[i] == 2 * sum / 3)
                {
                    twothird[i]++;
                }
            }

            for (ll i = n - 1; i > 0; i--)
            {
                twothird[i - 1] += twothird[i];
            }

            ll ans = 0;
            for (ll i = 0; i < n; i++)
            {
                if (third[i] == 1)
                {
                    ans += (twothird[i]);
                }
            }
            cout << ans << "\n";
        }
    }
    else
    {
        cout << 0 << "\n";
    }
}