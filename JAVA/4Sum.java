//Problem link:https://leetcode.com/problems/4sum/


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums); // Sort the input array in ascending order.
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(nums, (long) target, 0, result, temp, 4); // Use long data type for target.
        return result; // Return the result list containing unique quadruplets.
    }

    private void helper(int[] nums, long target, int start, List<List<Integer>> result, List<Integer> temp, int numNeed) {
        if (numNeed != 2) {
            for (int i = start; i < nums.length - numNeed + 1; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue; // Skip duplicates to avoid duplicate combinations.
                }
                temp.add(nums[i]); // Add the current number to the combination.
                helper(nums, target - nums[i], i + 1, result, temp, numNeed - 1); // Recursively find the next number(s).
                temp.remove(temp.size() - 1); // Remove the last number to backtrack.
            }
            return;
        }

        // If we need exactly 2 numbers, perform a two-pointer approach.
        int l = start;
        int r = nums.length - 1;
        while (l < r) {
            long total = (long) nums[l] + nums[r];
            if (total < target) {
                l++;
            } else if (total > target) {
                r--;
            } else {
                temp.add(nums[l]); // Add the left number to the combination.
                temp.add(nums[r]); // Add the right number to the combination.
                result.add(new ArrayList<>(temp)); // Store the valid quadruplet in the result list.
                temp.remove(temp.size() - 1); // Remove the right number to backtrack.
                temp.remove(temp.size() - 1); // Remove the left number to backtrack.
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++; // Skip duplicates on the left.
                }
            }
        }
    }
}
