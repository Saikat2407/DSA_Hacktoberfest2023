//Leetcode question number 1095.
// https://leetcode.com/problems/find-in-mountain-array/description/

//Approach:-
// Now we have to find the element in the Mountain array.
// We are also given that duplicate elements can also be present.
// So for doing this, first we will find out the Peak element or the Mountain element in the array.
// Then, we will apply binary search in the left side and right side of the peak element.
// And then if we find the element in both the halves, return the indice of left half.
// If not found in left half, return the indice of right half,
// Else return -1 as we didn't find the target element.


/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 

class Solution {
    public int findPeak(MountainArray arr)
    {
        int start=0;
        int end=arr.length()-1;
        int mid=0;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(arr.get(mid)<arr.get(mid+1))
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return end;
    }
    public int binarySearchLeft(MountainArray arr,int target,int start,int end)
    {
        int low=start;
        int high=end;
        int mid=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr.get(mid)==target)
            {
                return mid;
            }
            else if(arr.get(mid)<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }

    public int binarySearchRight(MountainArray arr,int target,int start,int end)
    {
        int low=start;
        int high=end;
        int mid=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr.get(mid)==target)
            {
                return mid;
            }
            else if(arr.get(mid)<target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }

    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peakIndex=findPeak(mountainArr);
        int minIndex=binarySearchLeft(mountainArr,target,0,peakIndex);
        int maxIndex=binarySearchRight(mountainArr,target,peakIndex+1,mountainArr.length()-1);
        if(minIndex!=-1)
        {
            return minIndex;
        }
        else if(maxIndex!=-1)
        {
            return maxIndex;
        }
        else
        {
            return -1;
        }
    
    }
}