# https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=leetcode-75
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        x=nums[:]
        heapq.heapify(x)
        for i in range(len(nums)-k):
            heapq.heappop(x)
        return x[0]