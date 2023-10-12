class Solution {
public:
    int helper(vector<int> &v, int i,int dp[])
    {
        if(i>=v.size())
        return 0;
        if(i==v.size()-1)
        return v[i];
        if(dp[i]!=-1)
        return dp[i];
        int lr=helper(v,i+2,dp)+v[i];
        int rt=v[i]+helper(v,i+3,dp);
        return dp[i]= max(lr,rt);
    }
    int rob(vector<int>& nums) {
        int mx=-1;
        int dp[101];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++)
        {
            mx=max(mx,helper(nums,i,dp));
        }
        return mx;
    }
};