/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1,
                                   vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            idx[nums1[i]] = i;
        }
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < m; i++) {
            int t = nums2[i];
            while (!st.empty() && t > st.top()) {
                int j = st.top();
                st.pop();
                ans[idx[j]] = t;
            }
            if (idx.contains(t)) {
                st.push(t);
            }
        }
        return ans;
    }
};
// @lc code=end
