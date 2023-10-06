// Find the index of first occurance of a pattern in a string
// Leetcode Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Question : Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Solution: 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};

int main()
{
    Solution ob;
    cout<<ob.strStr("xyzxyzxyz", "yz");

}