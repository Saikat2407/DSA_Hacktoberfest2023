#include<bits/stdc++.h>
using namespace std;
int Sumequals_K(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
int main(){
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        long long ans=Sumequals_K(vec,k);
        cout<<ans<<endl;
        return 0;
    }