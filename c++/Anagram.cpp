#include <bits/stdc++.h>
using namespace std;



bool isAnagram(string s,string t){
    int freqTable[256]={0};
    for(int i=0;i<s.size();i++){
        freqTable[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        freqTable[t[i]]--;
    }
    for(int i=0;i<256;i++){
        if(freqTable[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){

    string s="anagram",t="ganama";
    if(isAnagram(s,t)){
        cout<<"Anagram"<<endl;
    }
    else{
         cout<<"Not A Anagram";
        }
    return 0;
}