/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <vector>
using namespace std;

// @lc code=start
class NumArray {
public:
    vector<int> pre_sum;
    NumArray(vector<int> &nums) {
        int n = nums.size();
        pre_sum.resize(n + 1);
        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
