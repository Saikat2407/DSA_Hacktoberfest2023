#include <bits/stdc++.h>
using namespace std;

void vectors(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
}
int main(){
    vectors();
    return 0;
    
}