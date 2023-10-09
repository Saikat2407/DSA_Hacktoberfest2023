//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/0
//User function Template for Java

class Solution
{
    //Function to merge the arrays.
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        // code here 
        int x=n-1,y=0;
        long temp=0;
        while(x>=0 && y<m)
        {
            if(arr1[x]>arr2[y])
            {
                temp=arr1[x];
                arr1[x]=arr2[y];
                arr2[y]=temp;
            }
            else
                break;
            x--;
            y++;
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
    }
}