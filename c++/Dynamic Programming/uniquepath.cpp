// question link : https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;

class Solution {

    // approach :- when rows= m and cols= n is given
    // formula for unique path with will be 
    
    // Σ(i= rows-2 --> rows-2+col-1 ) combination(i,rows-2)

    // time : O(N*M)
    // space : O(1)

    long long combination(int N , int r){

        if(r > N/2) r = N-r;

        if(r==0) return 1;
        else if(r==1) return N;

        long long num = 1 , deno = 1;

        for(int i=1;i<=r;i++){
            num *= (N+1-i);
            deno *= i;
        }
        // cout<<num<<" "<<deno<<endl;

        return num/deno;
    }

public:
    int uniquePaths(int m, int n) {
        int ans=0;
        int a,b;

        if(m>n) a=m,b=n;
        else a=n,b=m;
        
        for(int i=a-2;i<a-2+b;i++){
            ans += combination(i,a-2);
        }

        return ans;
    }
};


int main(){
    Solution sol;

    int m,n;
    cin>>m>>n;
    cout<< sol.uniquePaths(m,n)<<endl;

    return 0;
}