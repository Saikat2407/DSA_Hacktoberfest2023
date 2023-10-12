
//SORTING IN ARRAY "SELECTION SORT"

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)      //find smallest digit index and swap  it with 0th element 
        {                                  // 64 25 12 22 11 -- array
            int pos=i;                     // i=0 
                                           //pos=0  j=1 ----- 25<64 true update pos=j=1 
            if(a[j]<a[pos]){               //pos=1  j=2 ----- 12<25 true update pos=j=2
                pos=j;                    //pos =2  j=3 ----- 22<12 false remain same pos=2
            }                             //pos =2  j=4 ----- 12<11 true update pos=j=4 
            if(pos!=i){
                int temp = a[i];            //check  pos!=i  --- 4!=0 swap (0,4)
                a[i]=a[pos];           
                a[pos]=temp;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
