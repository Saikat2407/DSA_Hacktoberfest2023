//Code, Leetcode QUES with Explanation
// Problem Link:https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:

int binary_search(vector<int>&nums,int start,int x){
    int end=nums.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(nums[mid]==x){
            return mid;
        }
        else if(x>nums[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            if(binary_search(nums,i+1,nums[i]+k)!=-1){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }
   
};

        