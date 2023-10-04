"""896. Monotonic Array 
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise."""


class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        is_increasing = True  # Indicates if the array is increasing.
        is_decreasing = True  # Indicates if the array is decreasing.

        # Check if the array is either increasing or non-increasing.
        for i in range(1, len(nums)):
            # Check increasing condition.
            if nums[i] < nums[i - 1]:
                is_increasing = False

            # Check decreasing condition.
            elif nums[i] > nums[i - 1]:
                is_decreasing = False

            # If it is neither increasing nor decreasing then don't continue the loop.
            if not is_increasing and not is_decreasing:
                break

        return is_increasing or is_decreasing  # Return true if either condition is met