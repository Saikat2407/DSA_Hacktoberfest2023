#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        map<int,int>m,m1;
        for(int i = 0 ; i < arr.size() ;i++)
        {
            m[arr[i]]++;
        }
        for(auto it=m.begin(); it!=m.end();it++)
        {
                cout<<it->first<<" "<<it->second;
                cout<<endl;
        }
        for(auto it=m.begin(); it!=m.end();it++)
        {
                m1[m[it->second]]++;
        }
       return m.size()==m1.size();
    }
};

int main()
{
    Solution ob;
    vector<int>arr;
    cout<<"enter the size of an array\n";
    int n,a;
    cin>>n;
    cout<<"enter the numbers\n";
    
    for(int i = 0 ;i < n ; i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<"The different numbers and their frequencies:- \n";
    ob.uniqueOccurrences(arr);
}
