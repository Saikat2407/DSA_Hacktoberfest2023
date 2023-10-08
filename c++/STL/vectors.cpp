#include <bits/stdc++.h>
using namespace std;

void vectors()
{
    // vector<int> v;
    // // insert values
    // v.push_back(1);
    // v.emplace_back(2);
    // // print the vector
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout<<endl;
    // // vector<pair<int,int>> v1;
    // // v1.push_back({1,2});
    // // cout<<v1[0].first<<" "<<v1[0].second;
    // vector<int>::iterator it ;
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout<<endl;
    // vector<int>::iterator it1= v.begin();
    // cout<<*it1<<endl;
    // it1++;
    // cout<<*it1<<endl;
    // vector<int>::iterator it2= v.end();
    // it2--;
    // cout<<*it2<<endl;

    // for(auto it=v.begin();it!=v.end();it++)
    // {
    //     cout<<*it<<" ";
    // }

    // cout<<endl;

    // for(auto it :v){
    //     cout<<it<<" ";
    // }

    vector<int> v;
    v.emplace_back(5);
    //print vector 
    for(auto it:v){
        cout<<it;
    }

}
int main()
{
    vectors();
    return 0;
}