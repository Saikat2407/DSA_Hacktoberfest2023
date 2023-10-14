PROBLEM:https://leetcode.com/problems/reverse-words-in-a-string-iii/description/?envType=daily-question&envId=2023-10-01
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=c-cT9b2YyXk

/*
  METHOD 1
  TC:O(N) coz at max we are traversing an element twice
  SC:O(1)
*/


class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                int j=i;
                while(j<n && s[j]!=' '){
                    j++;
                }
                reverse(begin(s)+i,begin(s)+j);
                i=j;
            }
        }
        return s;
    }
};


/*
Method 2
using tokenization
*/

#include<bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token="";
        string result="";
        while(ss>>token){
            reverse(begin(token),end(token));
            result+=token+" ";
        }
        return result.substr(0,result.length()-1);
    }
};
