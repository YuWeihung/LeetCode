/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 */
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = nums[i], l = left[i], r = right[i];
            if (l < k && k < r) {
                ans = max(ans, h * (r - l - 1));
            }
        }
        return ans;
    }
};
// @lc code=end
