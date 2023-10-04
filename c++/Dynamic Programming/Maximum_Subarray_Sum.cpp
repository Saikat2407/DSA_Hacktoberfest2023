// Link to the following problem
// https://leetcode.com/problems/maximum-product-subarray/

// Given an integer array nums, find a subarray that has the largest product, and return the product.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxi = INT_MIN;
        int pre = 1;
        int suff = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (pre == 0)
                pre = 1;

            pre *= nums[i];
            if (pre > maxi)
                maxi = max(pre, maxi);
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (suff == 0)
                suff = 1;

            suff *= nums[i];
            if (suff > maxi)
                maxi = max(suff, maxi);
        }

        return maxi;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {2, 3, -2, 4, -1};
    int result = solution.maxProduct(nums);

    cout << "Maximum product subarray: " << result << endl;

    return 0;
}
