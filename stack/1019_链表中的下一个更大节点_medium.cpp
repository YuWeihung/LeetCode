/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */
#include "list_node.h"
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        stack<pair<int, int>> st;
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            while (!st.empty() && cur->val > st.top().first) {
                ans[st.top().second] = cur->val;
                st.pop();
            }
            st.emplace(cur->val, ans.size());
            ans.push_back(0);
        }
        return ans;
    }
};
// @lc code=end
