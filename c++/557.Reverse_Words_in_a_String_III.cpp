// leetcode problem link - https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
   void reverseS(int j, int k , string &s){
      while(j<k){
          char temp=s[j]; 
          s[j++]=s[k]; 
          s[k--]=temp; 
      }
   }
    string reverseWords(string s) {
        int n=s.size(); 
        int j=0; 
        for(int i=0; i<n; i++){
            if(s[i] == ' '){
                 reverseS(j,i-1,s);
                 j=i+1; 
                 } 
        }
        reverseS(j,n-1,s); 
        return s; 
    }
};
