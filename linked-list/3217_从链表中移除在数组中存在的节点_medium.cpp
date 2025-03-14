/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
 */
#include "list_node.h"
#include <unordered_set>
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next != nullptr) {
            if (st.count(cur->next->val) == 1) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
