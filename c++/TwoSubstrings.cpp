// Solution of codeforces problem Two Substring https://codeforces.com/problemset/problem/550/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define M 1
//tc fori forj
//1 sec -10^8
//max len of arr -10^7
//max len of vector 2147483648 < 10^10
//for loops not more that 10^5
//QUALITY>QUANTITY
// NO WRONG SUBMISSIONS ONLY CORRECT ANSWERS
//-------------------------------------------------------------------------------------------------------------------------------
//
//FIRST YOU SHOULD GET THE LOGIC CORRECTLY , READ THE QUESTION CORRECTLY
//
//-------------------------------------------------------------------------------------------------------------------------------


void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    vector <ll> v1;
    vector <ll> v2;
    for (ll i=0;i<s.size()-1;i++)
    {

        if (s[i]=='A' and s[i+1]=='B')
        {
            v1.pb(i);
        }
        if (s[i]=='B' and s[i+1]=='A')
        {
            v2.pb(i);
        }
    }
    if (v1.size()==0 or  v2.size()==0)
    {
        cout<<"NO"<<"\n";
    }
    else if (v1.size()==1 and v2.size()==1)
    {
        if ((abs (v1[0]-v2[0]))==1)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            cout<<"YES"<<"\n";
        }
    }
    else if (v1.size()==2 and v2.size()==1)
    {
        if (v1[0]+1==v2[0] and v2[0]+1==v1[1])
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            cout<<"YES"<<"\n";
        }
    }
     else if (v2.size()==2 and v1.size()==1)
    {
        if (v2[0]+1==v1[0] and v1[0]+1==v2[1])
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            cout<<"YES"<<"\n";
        }
    }
    else
    {
        cout<<"YES"<<"\n";
    }


}