// LEETCODE PROBLEM :  Trapping Rain Water

// LINK TO THE PROBLEM : https://leetcode.com/problems/trapping-rain-water/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, var;
        int n = height.size();
        std::vector<int> left(n), right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = std::max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = std::max(right[i + 1], height[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            var = std::min(left[i - 1], right[i + 1]);
            if (var > height[i]) {
                water += var - height[i];
            }
        }

        return water;
    }
};

int main() {

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    int trappedWater = solution.trap(height);
    cout << "Trapped water: " << trappedWater << std::endl;

    return 0;
}
