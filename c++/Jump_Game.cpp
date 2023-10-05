class Solution {
    vector<int> memo;
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=true;
        
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
  }
};
