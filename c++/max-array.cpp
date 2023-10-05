  /*Find minimum and maximum element in an array

  Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

  Problem Link: https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/0
*/

struct pair getMinMax(long long a[],long long  n) {
    int i; long max=a[0]; 
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    long min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }
    return {min,max};
    
}