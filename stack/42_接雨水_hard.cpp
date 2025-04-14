/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        int ans = 0;
        int n = height.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int h = height[i];
            while (!st.empty() && h >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], h) - bottom_h;
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
