#include<iostream>
using namespace std;

int main()
{
    int a[100],n,i,j,temp;
    cout<<"\nEnter size : ";
    cin>>n;
 
    cout<<"\nEnter "<<n<<" Value :"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
 
    cout<<"\nSorted Array is : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
