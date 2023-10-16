package main

import (
	"fmt"
	"math"
	"strings"
)

/*
*
Problem Statement -
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Output -
1.      minSubArrayLen(7, [2, 3, 1, 2, 4, 3]): 2
----------------------------------------------------------------------------------------------------
2.      minSubArrayLen(4, [1, 4, 4]): 1
----------------------------------------------------------------------------------------------------
3.      minSubArrayLen(11, [1, 1, 1, 1, 1, 1, 1, 1]): 0
----------------------------------------------------------------------------------------------------
4.      minSubArrayLen(10, [1, 2, 3, 4]): 4
----------------------------------------------------------------------------------------------------
5.      minSubArrayLen(5, [1, 2, 1, 3]): 3
----------------------------------------------------------------------------------------------------
6.      minSubArrayLen(15, [5, 4, 9, 8, 11, 3, 7, 12, 15, 44]): 1
----------------------------------------------------------------------------------------------------

Solution
We use the windowSize variable to store the size of the minimum subarray, initializing it to MaxInt64.
We use a start variable to track the left end of the subarray. Initially, we’ll set it to 0.
We loop over the input array using an end variable to track the right end of the subarray.
In each iteration, we add the value that has just entered the window to the running sum of the window contents.
If the sum of our current subarray exceeds or equals the target value,
we’ll compare the current subarray size with the window size already present.
The smaller of the two values will be stored in windowSize. We then try to find a smaller subarray that meets the same condition.
We slide the starting point of the subarray forward and check the sum from that point to the end of the subarray,
checking the condition and updating windowSize where applicable.
We repeat the process until the end of the array is reached. If the required minimum subarray is present, we return its length.
*/
func minSubArrayLen(target int, nums []int) int {
	// write your code here
	// your code will replace this placeholder return statement
	// Initializing windowSize to a max number
	windowSize := math.MaxInt64

	// Initialize start pointer to 0 and sum to 0
	start, totalSum := 0, 0

	for end, _ := range nums {
		totalSum += nums[end]
		// Check if we can remove elements from the start side of the subarray
		// while still satisfying the target condition
		for totalSum >= target {
			// Finding size of current subarray
			currSubArrSize := (end + 1) - start
			windowSize = min(windowSize, currSubArrSize)
			totalSum -= nums[start]
			start += 1
		}
	}
	if windowSize != math.MaxInt64 {
		return windowSize
	} else {
		return 0
	}
}

func min(v1 int, v2 int) int {
	if v1 < v2 {
		return v1
	}
	return v2
}

func main() {
	targets := []int{
		7,
		4,
		11,
		10,
		5,
		15,
	}
	numsList := [][]int{
		{2, 3, 1, 2, 4, 3},
		{1, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 3, 4}, {1, 2, 1, 3},
		{5, 4, 9, 8, 11, 3, 7, 12, 15, 44},
	}
	for i, target := range targets {
		result := minSubArrayLen(target, numsList[i])
		fmt.Printf("%d.\tminSubArrayLen(%d, %s): %d\n", i+1, target,
			strings.Replace(fmt.Sprint(numsList[i]), " ", ", ", -1), result)
		fmt.Printf("%s\n", strings.Repeat("-", 100))
	}
}
