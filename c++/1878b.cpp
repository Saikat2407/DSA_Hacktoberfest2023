// https://codeforces.com/contest/1878/problem/B

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int t, n, index, start;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> ans;
        ans.push_back(6);
        ans.push_back(7);
        index = 2;
        start = 8;
        while (ans.size() != n)
        {
            for (int i = start; i < INT_MAX; i++)
            {
                if ((3 * i) % (ans[index - 1] + ans[index - 2]) != 0)
                {
                    ans.push_back(i);
                    index++;
                    start = i + 1;
                    break;
                }
            }
        }
        for (auto j = ans.begin(); j != ans.end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}