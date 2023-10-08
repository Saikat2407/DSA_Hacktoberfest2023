#User function template for Python

class Solution:	
	def binarysearch(self, arr, n, k):
		start=0
        end=n-1
        while start<=end:
            mid=(start+end)//2
            if arr[mid]==k:
                return mid
            elif arr[mid]>k:
                end=mid-1
            else:
                start=mid+1
        return -1

