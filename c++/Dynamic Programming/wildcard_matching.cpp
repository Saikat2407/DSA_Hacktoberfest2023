class Solution {
public:
    bool spaceoptimized(string &s,string &p){
        int m = s.size();
        int n = p.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        prev[0]=1;
        for(int j=1; j<=p.length(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*'){flag = false;break;}
            }
            prev[j] = flag;
        }
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(s[i-1]==p[j-1]|| p[j-1]=='?')
                 curr[j] =  prev[j-1];
                else if(p[j-1]=='*')
                curr[j] = prev[j]||curr[j-1];
                else curr[j]= false;
            }
            prev=curr;
        }
        return prev[n];
    }
    bool bottomup(string &s,string &p){
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int j=1; j<=p.length(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*'){flag = false;break;}
            }
            dp[0][j] = flag;
        }
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(s[i-1]==p[j-1]|| p[j-1]=='?')
                 dp[i][j] =  dp[i-1][j-1];
                else if(p[j-1]=='*')
                dp[i][j] = dp[i-1][j]||dp[i][j-1];
                else dp[i][j]= false;
            }
        }
        return dp[m][n];
    }

    bool topdown(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(i>=0 && j<0)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j]|| p[j]=='?')return dp[i][j] =  solve(s,p,i-1,j-1,dp);
        else if(p[j]=='*')return dp[i][j] =  solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        else return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+3,vector<int>(n+3,-1));
        // return topdown(s,p,m-1,n-1,dp);
        // return bottomup(s,p);
        // return spaceoptimized(s,p);
    }
};
