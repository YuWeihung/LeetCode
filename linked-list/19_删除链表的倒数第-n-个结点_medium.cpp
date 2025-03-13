/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *right = dummy, *left = dummy;
        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        while (right->next != nullptr) {
            right = right->next;
            left = left->next;
        }
        ListNode *next = left->next;
        left->next = left->next->next;
        delete next;
        return dummy->next;
    }
};
// @lc code=end
