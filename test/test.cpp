#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

void test() {
    Solution solution;

    // 测试用例 1: 目标值存在于数组中
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    int result1 = solution.searchInsert(nums1, target1);
    assert(result1 == 2);
    std::cout << "Test case 1 passed!" << std::endl;

    // 测试用例 2: 目标值不存在，应插入到中间位置
    std::vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    int result2 = solution.searchInsert(nums2, target2);
    assert(result2 == 1);
    std::cout << "Test case 2 passed!" << std::endl;

    // 测试用例 3: 目标值不存在，应插入到末尾
    std::vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    int result3 = solution.searchInsert(nums3, target3);
    assert(result3 == 4);
    std::cout << "Test case 3 passed!" << std::endl;

    // 测试用例 4: 空数组
    std::vector<int> nums4 = {};
    int target4 = 1;
    int result4 = solution.searchInsert(nums4, target4);
    assert(result4 == 0);
    std::cout << "Test case 4 passed!" << std::endl;

    // 测试用例 5: 目标值小于数组中的所有元素
    std::vector<int> nums5 = {2, 4, 6, 8};
    int target5 = 1;
    int result5 = solution.searchInsert(nums5, target5);
    assert(result5 == 0);
    std::cout << "Test case 5 passed!" << std::endl;

    // 测试用例 6: 目标值等于数组中的最后一个元素
    std::vector<int> nums6 = {2, 4, 6, 8};
    int target6 = 8;
    int result6 = solution.searchInsert(nums6, target6);
    assert(result6 == 3);
    std::cout << "Test case 6 passed!" << std::endl;
}

int main() {
    test();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}