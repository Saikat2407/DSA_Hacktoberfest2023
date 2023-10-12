Problem statement-Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6
numbers form the longest consecutive
subsquence.


code:
class Solution
{   
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
	static int findLongestConseqSubseq(int arr[], int N)
	{
	   // add your code here
	   HashSet<Integer> set=new HashSet<>();
	   for(int i=0;i<N;i++)
	     set.add(arr[i]);
	   int res=0;
	   for(int i=0;i<N;i++)
	   {
	       if(set.contains(arr[i]-1)==false)
	       {
	           int curr=1;
	           while(set.contains(arr[i]+curr))
	            curr++;
	           res=Math.max(res,curr);
	       }
	   }
	   return res;
	}
}
