PROBLEM:https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-10-11


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m=flowers.size();
        int n=people.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int curr=people[i];
            int cnt=0;
            for(int j=0;j<m;j++){
                int low=flowers[j][0];
                int hi=flowers[j][1];
                if(curr>=low && curr<=hi)cnt++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};
