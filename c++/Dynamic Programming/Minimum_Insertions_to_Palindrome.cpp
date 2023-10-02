#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == s[n - 1 - j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return n - dp[n][n];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    int minInsertions = solution.minInsertions(s);
    cout << "Minimum Insertions: " << minInsertions << endl;  //output is : 5, since palindrome will be: "leetcodocteel"
    return 0;
}
