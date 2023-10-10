/*MY SOLUTION OF PROBLEM B FROM LAST CODEFORCES ROUND 
https://codeforces.com/contest/1886/problem/B 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++)
    {
        double px, py;
        cin >> px >> py;
        double ax, ay;
        cin >> ax >> ay;
        double bx, by;
        cin >> bx >> by;
        int state;
        double ao = sqrt(pow(ax,2) + pow(ay,2));
        double bo = sqrt(pow(bx,2) + pow(by,2));
        double ap = sqrt(pow(px - ax,2) + pow(py - ay,2));
        double bp = sqrt(pow(px - bx,2) + pow(py - by,2));
        double ab = sqrt(pow(ax - bx,2) + pow(ay - by,2));
        if (ao <= bo && ap <= bp) state = 1;
        else if (ao > bo && ap > bp) state = 2;
        else if (ao <= bo && ap > bp) state = 3;
        else state = 4;
        double ans;
        switch (state)
        {
            case 1 : {
                ans = max(ao, ap);
            }
            break;
            case 2: {
                ans = max(bo, bp);
            }
            break;
            case 3: {
                ans = max(ao, bp);
                ans = max(ans, ab / 2);
            }
            break;
            case 4:
            {
                ans = max(ap, bo);
                ans = max(ans, ab / 2);
            }
            break;
        }
        cout << setprecision(8) << ans << "\n";        
    }
    return 0;
}
