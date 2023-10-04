#include <bits\stdc++.h>
using namespace std;

void solve(string str, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        // backtrack
        swap(str[index], str[i]);
    }
}

vector<string> permutations(string str)
{
    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    return ans;
}
