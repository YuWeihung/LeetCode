/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include "list_node.h"

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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *p0 = dummy;
        for (int i = 0; i < left - 1; i++) {
            p0 = p0->next;
        }
        ListNode *pre = nullptr, *cur = p0->next;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;
    }
};
// @lc code=end
