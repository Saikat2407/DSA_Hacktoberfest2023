// Question link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;

        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                int k=i-1;
                while(j<k){
                    s[k]=s[k]+s[j];
                    s[j]=s[k]-s[j];
                    s[k]=s[k]-s[j];
                    k--;
                    j++;
                }
                j=i+1;
                i++;
            }
        }
         int k=i-1;
                while(j<k){
                    s[k]=s[k]+s[j];
                    s[j]=s[k]-s[j];
                    s[k]=s[k]-s[j];
                    k--;
                    j++;
                }


        return s;
    }
};
