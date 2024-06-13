#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                maxLen = 2;
            }
        }
        for (int i = 3; i <= n; i++)
        {
            for (int j = 0; j < n - i + 1; j++)
            {
                int k = j + i - 1;
                if (s[j] == s[k] && dp[j + 1][k - 1])
                {
                    dp[j][k] = 1;
                    if (i > maxLen)
                    {
                        start = j;
                        maxLen = i;
                    }
                }
            }
        }
        ans = s.substr(start, maxLen);
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    return 0;
}