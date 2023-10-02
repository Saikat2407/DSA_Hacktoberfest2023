//https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/
class Solution {
public:
    string smallestString(string s) {
        int count=0;
        int n=s.size();
        if(n==1 && s[0]=='a'){
            s[0]='z';
        }
        else{
        for(int i=0;i<n;i++){
           if(s[i]!='a'){
               s[i]=s[i]-1;
               count=1;
           }
           else if(count){
               break;
           }
        }
        }
        if(count==0){
            s[n-1]='z';
        }
        return s;

    }
};

// Approach
// If string only contains 'a':

// Change last 'a' to 'z'
// If string contains other characters :

// Skip initial 'a'
// Change all characters to its previous characters until found and 'a' or you have traversed the whole string.

// Time complexity:
// O(n)

// Space complexity:
// O(1)