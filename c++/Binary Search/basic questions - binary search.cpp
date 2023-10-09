#include <iostream>
using namespace std;

// applied in a sorted array

// finding target element in a sorted array
int binarySearch(int *arr, int target, int size)
{
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
    }
    return -1;
}

// finding the first occurence of an element in a sorted array

int binarySearchFirstOccurence(int *arr, int target, int size)
{
    int l = 0;
    int r = size - 1;
    int res = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            r = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
    }
    return res;
}

// finding the last occurence of an element in a sorted array

int binarySearchLastOccurence(int *arr, int target, int size)
{
    int l = 0;
    int r = size - 1;
    int res = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            l = mid + 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
    }
    return res;
}

// Count of Occurrences: Given a sorted array, find the count of occurrences of a target element

int CountOccurence(int *arr, int target, int size)
{
    int l = binarySearchFirstOccurence(arr, target, size);
    int r = binarySearchLastOccurence(arr, target, size);

    int count = r - 1 + 1;
    return count;
}

// Square Root: Find the square root of a given number using binary search.
// since we'll search from 1 to the number whose sqr root is to be found we have sorted values
// we can apply bs

int SquareRoot(int target)
{
    int l = 0;
    int r = target ;
    int val;
    int res = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        val = mid * mid;

        if (val == target)
        {
            return mid;
        }
        else if (val < target)
        { // basically if target is 24 and we are on 4 so val = 4*4=16 < target(24) so we'll search on right but 5*5>24 
          // so hmara 4 chut jata isliye we stored it and then continued our search
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return res;
}



// Find Peak Element: Given an array that is in ascending order up to a certain point and then descending, find the peak element.

int PeakBinarySearch(int *arr,int size){
    // int res;
    // for(int i =0 ; i<size-1 ; i++){
    //     if(arr[i+1]<arr[i]){
    //         res = i;
    //         break;
    //     }
    // }

    // return res;

    // this was using linear search

    // using binary search
    
    int l = 0;
    int r = size - 1;
   

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid]>arr[mid+1])
        {
            r = mid; // ya to mid vla hi peak hoga ya usse peeche bhi ho sakte hai 12365412...hm agr 4 pr hue to bhi 4>1 hai pr peak to peeche h na 6 to hmne right = mid krke phir aur left m dhundha
        }
        else 
        {
            l = mid + 1;
        }
        
    }
    return l; // jb hm 3 par hoge to 3>6 to nhi hai to l = mid+1 mtb l bhi 6 pr aa jyega joki peak hai
    // return r ; ye bhi kaam krega as at the end left and right would be at the same position when the loop would break

}



// Questions left


// 7. **Search in Rotated Sorted Array**: Given a sorted array that has been rotated, implement a binary search to find a target element.

// 8. **Median of Two Sorted Arrays**: Given two sorted arrays, find the median element when they are combined.

// 9. **Find Minimum in Rotated Sorted Array**: Find the minimum element in a rotated sorted array.

// 10. **Allocate Minimum Pages**: Given an array representing the number of pages in N different books and M students, distribute the books in a way that minimizes the maximum number of pages a student reads.

// 11. **Find Kth Smallest Element in a Sorted Matrix**: Given a sorted matrix, find the Kth smallest element.

// 12. **Find the Peak Index**: Given an array where adjacent elements differ by at most 1, find the peak element's index.

// 13. **Minimum Difference Element**: Given a sorted array, find the element with the minimum absolute difference from a given value.

// 14. **Search Insert Position**: Given a sorted array and a target value, return the index where the target would be inserted.

// 15. **Find Closest Elements**: Given a sorted array and a target value, find k closest elements to the target.

// These are some common scenarios where binary search can be applied. Depending on the complexity of the problem, the implementation may vary, but the core concept of binary search remains the same. When preparing for interviews or coding challenges, it's a good idea to practice these types of questions to build your binary search skills.


