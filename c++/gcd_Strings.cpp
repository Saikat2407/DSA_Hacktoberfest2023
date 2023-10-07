// PROBLEM LINK - https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define pb push_back
string gcdStrings(string st1, string st2)
{
    // USING EUCLID'S ALGORITHM
    if(st1 + st2 != st2 + st1) return "";
    int len1 = st1.length(), len2 = st2.length();
    while(len1 != len2)
    {
        if(len1 > len2) len1 -= len2;
        else len2 -= len1;
    }
    return st1.substr(0, len1);

    // USING STL
    // if(st1 + st2 != st2 + st1) return "";
    // int len1 = st1.length(), len2 = st2.length();
    // return st1.substr(0, __gcd(len1, len2));
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << gcdStrings(str1, str2) << endl;
    return 0;
}