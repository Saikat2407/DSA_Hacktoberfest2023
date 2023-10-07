// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // 2 2 2 2 
        // 3 3 3 
        // 4 4
        // 7 2 2 3
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int count = 0;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            if(it->second == 1)
                return -1;
            int val = it->second;
            int rem = val%3;
            if(rem == 0)
                count = count+ val/3;
            else if(rem ==2)
            {
                count = count + (val/3) +1;
            }
            else if(rem == 1)
            {
                count = count + (val/3)+1;
            }
        }
        return count;
        
    }
};

// Intitution: We will just try to do operations by dividing it with 3 and making cases on variouus remainders