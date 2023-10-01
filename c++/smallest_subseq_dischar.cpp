/*
Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

Question : Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct
 characters of s exactly once.
*/
//Solution :
class Solution {
public:
    string smallestSubsequence(string s) {
        string st="";
        vector<int> v(26,0);
        vector<int> vis(26,0);
        for(int i=0;i<s.length();i++)
        v[s[i]-'a']++;
        for(int i=0;i<s.length();i++)
        {
            if(vis[s[i]-'a']==1)
            {
                v[s[i]-'a']--;
                continue;
            }
            if(st.size()==0)
            {
                st.push_back(s[i]);
                vis[s[i]-'a']=1;
                v[s[i]-'a']--;
            }
            else
            {
                if(st[st.size()-1]<s[i])
                {
                    st.push_back(s[i]);
                    vis[s[i]-'a']=1;
                    v[s[i]-'a']--;
                }
                else
                {
                    while(st.size()>0&&st[st.size()-1]>s[i]&&v[st[st.size()-1]-'a']>0)
                    {
                        vis[st[st.size()-1]-'a']=0;
                        st.pop_back();
                    }
                    st.push_back(s[i]);
                    v[s[i]-'a']--;
                    vis[s[i]-'a']=1;
                }
            }
        }
        return st;
    }
};