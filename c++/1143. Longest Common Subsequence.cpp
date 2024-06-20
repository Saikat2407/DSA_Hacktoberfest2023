// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.  A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.  For example, "ace" is a subsequence of "abcde". A common subsequence of two strings is a subsequence that is common to both strings.

#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    vector<vector <int> > dp();
        int curr=0, prev=0;
        int m = text1.length();
        int n = text2.length();
        for(int i = 0; i< m ;i++){
            for(int j = 0; j< n; j++){
                if(text2[j]==text1[i]){
                    curr=max(prev, curr+1);
                }
                else{
                    prev=curr;
                }
            }
        }
        return max(prev, curr);
    }


int main()
{
    string text1 = "abc", text2 = "def";
     cout<<longestCommonSubsequence(text1, text2);
    
}