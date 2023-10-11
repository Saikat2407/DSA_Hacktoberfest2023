//Leetcode Link: https://leetcode.com/problems/trapping-rain-water/

// Problem Statement:

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

//Solution

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left =0,right = n-1;
        int leftmax = height[0],rightmax = height[n-1];
        int ans=0;
        while(left<=right){
            if(height[left] < height[right] ){
                if(height[left] >= leftmax) leftmax = height[left];
                else ans += leftmax - height[left];
                left++;
            }else{
                if(height[right] >=rightmax) rightmax = height[right];
                else ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};