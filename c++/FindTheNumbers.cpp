// GFG solution of https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/0

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        map <int,int> m1;
        for (auto x : nums){
            m1[x]++;
        }
        vector <int> ans;
        for (auto x : m1)
        {
            if (x.second==1)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
        // Code here.
    }
};