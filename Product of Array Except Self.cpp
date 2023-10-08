class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int Lproduct = 1;
        for(int i=0; i<n; i++){
            Lproduct *= nums[i];
            ans.push_back(Lproduct);
                 
            }
        int Rproduct=1;
        for(int i=n-1; i>0; i--){
            ans[i]=ans[i-1]*Rproduct;
            Rproduct*=nums[i];
        }
        ans[0]=Rproduct;
           
        
        return ans;
    }
};
