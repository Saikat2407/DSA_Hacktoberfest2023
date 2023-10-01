#include <iostream>

using namespace std;

int lcs(string s, string t){ // Time and space compexity = O(mn)
    int m = s.size();
    int n = t.size();
    
    int **ans = new int*[m+1];
    
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
    }
    
    for(int i=0; i<=m; i++){
        ans[i][0] = 0;
    }
    
    for(int j=0; j<=n; j++){
        ans[0][j] = 0;
    }
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            
            if(s[m-i] == t[n-j]){ // Important line to understand
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else{
                int a = ans[i][j-1];
                int b = ans[i-1][j];
                ans[i][j] = max(a, b);
                
            }
        }
    }
    
    return ans[m][n];
    
    
}

int main()
{
    string s, t;
    cin >> s>>t;
    int ans = lcs(s, t);
    cout<<ans<<endl;

    return 0;
}


