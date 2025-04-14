/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size(), m = 2 * n;
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < m; i++) {
            int x = nums[i];
            while (!st.empty() && x > nums[st.top()]) {
                int j = st.top();
                st.pop();
                ans[j] = x;
            }
            if (i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
