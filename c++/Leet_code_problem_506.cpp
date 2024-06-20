/**
 * 506. Relative Ranks
     Solved
     Easy
     Topics
     Companies
     You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
*/

/**
 * ! Solution
 */

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> sa = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        priority_queue<pair<int, int>> an;
        int i = 0;
        for (i = 0; i < score.size(); i++)
        {
            an.push({score[i], i});
        }
        vector<string> ans(score.size(), "");
        i = 0;
        while (!an.empty())
        {
            if (i < 3)
            {

                ans[an.top().second] = sa[i];
                i++;
                an.pop();
            }
            else
            {

                ans[an.top().second] = to_string(i + 1);
                i++;
                an.pop();
            }
        }

        return ans;
    }
};

void print(vector<string> &arr)
{
    cout << endl;
    for (auto pr : arr)
    {
        cout << pr << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> score = {5, 4, 3, 2, 1};
    Solution sol;
    vector<string> ans = sol.findRelativeRanks(score);

    print(ans);

    return 0;
}