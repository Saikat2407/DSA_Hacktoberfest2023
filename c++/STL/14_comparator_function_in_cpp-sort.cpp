// Comparator Function is used in C++ Sort to sort in our customised order for different containers/data types.

/*  (1)
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int i=0; i<n; i++){           // O(n^2)
        for(int j=i+1; j<n; j++){
            if(v[i]>v[j]){
                swap(v[i],v[j]);      // Comparator   OR   // sort(v.begin(),v.end())
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
*/

//--------------------------------------------------------------------------------------------------------------

/* (2)
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){         // return whatever you want in sorted order. As a.first < b.first will be true, so no swapping happens.
        return a.first < b.first;   // whenever a.first < b.first will be false, swapping takes place to give desired order.
    }
    return a.second > b.second;     // if a.first == b.first, swap second element in decreasing order.
}

// bool cmp (int a, int b){
//     return a>b;
// }

int main(){

    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end(),cmp);       // OR  greater<pain<int,int> >()   in place of cmp  (inbuilt comparator)

    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<< v[i].second<<endl;
    }


    return 0;
}

*/
