// Problem Link:    https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>Set;
        int max=0;
        int start=0;
        int end=0;
        while(start<s.size()){
            auto it = Set.find(s[start]);
            if(it==Set.end()){
                if(start-end+1>max)
                max=start-end+1;
                Set.insert(s[start]);
                start++;
            }
            else{
                Set.erase(s[end]);
                end++;
            }
        }
        return max;
    }
};



//intuition: I kept on adding elements in the set until they are unique.