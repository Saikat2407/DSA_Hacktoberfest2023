## Maximum Money Robbery Without Alerting Police

Given an integer array `nums` representing the amount of money in each house, the goal is to find the maximum amount of money you can rob without alerting the police. A dynamic programming approach can be used.

### Solution

- Initialize two variables to track the maximum money for two cases:
  1. Money robbed so far without including the current house (`prev_max`).
  2. Money robbed so far including the current house (`curr_max`).

- Iterate through the houses:
  - Calculate the maximum money for the current house and update the variables:
    - `temp = curr_max`
    - `curr_max = max(prev_max + num, curr_max)`
    - `prev_max = temp`

- Return `curr_max` as the maximum money robbed considering all houses.

### Example Usage

```python
def rob(nums):
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    # Initialize two variables to keep track of the maximum money for two cases:
    # 1. Money robbed so far without including the current house.
    # 2. Money robbed so far including the current house.
    prev_max = 0
    curr_max = 0

    for num in nums:
        # Calculate the maximum money for the current house and update the variables.
        temp = curr_max
        curr_max = max(prev_max + num, curr_max)
        prev_max = temp

    # Return the maximum money robbed considering all houses.
    return curr_max

# Example usage:
nums = [2, 7, 9, 3, 1]
result = rob(nums)
print(result)  # Output: 12
```
This code **iterates through the houses** and **calculates the maximum money you can rob without alerting the police**, considering both **robbing** and **skipping** the current house. **It returns the maximum amount of money you can rob.**

