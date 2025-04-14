/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!st.empty() && h > heights[st.top()]) {
                ans[st.top()]++;
                st.pop();
            }
            if (!st.empty()) {
                ans[st.top()]++;
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
