class Solution {
public:
    int LPS(string s1,string s2,int n,int m){
        vector<vector<int>>mem(s1.length()+1,vector<int>(s1.length()+1,0));
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1 ; j<=m ;j++){
                if(s1[i-1]==s2[j-1])
                    mem[i][j] = 1+mem[i-1][j-1];
                else
                    mem[i][j] = max(mem[i][j-1],mem[i-1][j]);
            }
        }
        return mem[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        return LPS(s1,s,s.length(),s.length());
    }
};
