/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *node0 = dummy;
        ListNode *node1 = head;
        while (node1 != nullptr && node1->next != nullptr) {
            ListNode *node2 = node1->next;
            ListNode *node3 = node1->next->next;

            node0->next = node2;
            node2->next = node1;
            node1->next = node3;

            node0 = node1;
            node1 = node3;
        }
        return dummy->next;
    }
};
// @lc code=end
