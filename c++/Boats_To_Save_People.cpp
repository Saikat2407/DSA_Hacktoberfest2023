#include<bits/stdc++.h>
using namespace std;

/*You are given an array people where people[i] is the weight of the ith person
,and an infinite number of boats where each boat can carry a maximum weight of limit.
 Each boat carries at most two people at the same time, provided the sum of the weight
 of those people is at most limit.
Return the minimum number of boats to carry every given person.*/

int numRescueBoats(vector<int>& arr, int limit)
{
    //simple greedy approach
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int ans=0;

    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]<=limit)
        {
            j--;
            i++;
            ans++;
        }
        else
        {
            j--;
        }
    }

    ans=ans+(n-2*ans);
    return ans;
}