// Leetcode Problem no. 75
// https://leetcode.com/problems/sort-colors/

// Solution :

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;

            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};