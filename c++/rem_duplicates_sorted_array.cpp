//Qn.link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums);

int main() {
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int newSize = removeDuplicates(nums);
    
    std::cout << "After removing duplicates, the size is: " << newSize << std::endl;
    for (int i = 0; i < newSize; i++) {
        std::cout << nums[i] << " ";
    }
    return 0;
}
int removeDuplicates(std::vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    std::vector<int> a;
    int ele;
    if (n == 0) return 0;

    ele = nums[0];
    a.push_back(ele);

    for (int i = 1; i < n; i++) {
        if (ele != nums[i]) {
            ele = nums[i];
            a.push_back(ele);
        }
    }
    nums = a;  // Update the original vector
    return a.size();
}
