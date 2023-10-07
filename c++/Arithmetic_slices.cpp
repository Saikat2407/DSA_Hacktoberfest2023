//413. Arithmetic Slices
//https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     
        int n=nums.size();
        
        if(n<3)
            return 0;
        
        int count=0,res=0;
        for(int i=1;i<n-1;i++){
            if(nums[i-1]-nums[i]==nums[i]-nums[i+1]){
                count++;
                res+=count;
            }
            else
                count=0;
        }
        
        return res;
    }
};