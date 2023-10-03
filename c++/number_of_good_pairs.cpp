// Leetcode POTD(03/10/2023) - https://leetcode.com/problems/number-of-good-pairs/
// C++ solution in O(n) TC

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> maps;
        for(int i = 0; i < nums.size(); i++){
            maps[nums[i]]++;
        }
        int count = 0;
        for(auto i : maps){
            int occur = i.second;
            count += occur * (occur - 1) / 2;
        }
        return count;
    }
};