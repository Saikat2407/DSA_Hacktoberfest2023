// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

public class subArraySumEqualsK {

    public static int subarraySum(int[] nums, int k) {
        // this count variable counting total subarray's having sum equals target k.
        int count = 0;
        // nested loops making the subarray's one by one.
        for (int i = 0; i < nums.length; i++) {
            // initializing the sum variable- help in sum's up the subarray elements
            int sum = 0;
            for (int e = i; e < nums.length; e++) {
                sum += nums[e];
                // sum checker- checking the sum of array's.
                if (sum == k) {
                    count++;
                }
            }
        }
        // returning answer.
        return count;
    }

    public static void main(String[] args) {

        int[] nums = { 1, 1, 1 };

        int k = 2;

        System.out.println(subarraySum(nums, k));
    }
}

// Output

// 2
