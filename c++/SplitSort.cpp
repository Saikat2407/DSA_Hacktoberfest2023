#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
 int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    map <int, int> m;
    for(int i=0; i<n;i++){
        m[arr[i]]=i;
    
    }
    int count=0;
    for(int i=0; i<=n; i++){
        if(m[i]<m[i-1]){
            count++;
        }
    }
    cout<<count<<endl;
    }
 return 0;
 }