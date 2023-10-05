/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        int l,r,x;
        for(int i=0;i<n;i++)
        {
           x=arr[i];
           l=i+1;
           r=n-1;
         for(int j=i+1;j<n-1;j++)
         {
           if (x+arr[l]+arr[r] == 0)
             return true;
           if (x+arr[l]+arr[r] < 0)
             l++;
           else if(x+arr[l]+arr[r] > 0)
             r--;
    }
        }
        return false;
        
        //Your code here
    }
};
