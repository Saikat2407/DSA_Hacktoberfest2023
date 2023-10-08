#include <bits/stdc++.h>
using namespace std;

void pairs(){
    pair <int,int> p={1,2};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int, pair<int,int>> p1={1,{2,3}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
    pair<int,int> arr[]={{1,2},{2,3},{3,4}};
    cout<<arr[1].second<<" ";
}

void vectors(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
}
int main(){
    pairs();
    return 0;
}