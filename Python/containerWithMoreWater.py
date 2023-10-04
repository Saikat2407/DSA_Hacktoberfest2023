class Solution(object):
    def maxArea(self, height):
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            h = min(height[left], height[right])
            width = right - left
            area = h * width
            max_area = max(max_area, area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area

# Create an instance of the Solution class
solution = Solution()

# Define the height array
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

# Call the maxArea method with the height argument
result = solution.maxArea(height)
print(result)
