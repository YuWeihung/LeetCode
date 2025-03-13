/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            n++;
            cur = cur->next;
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *p0 = dummy;
        ListNode *pre = nullptr;
        cur = p0->next;
        ListNode *next;
        while (n >= k) {
            n -= k;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            next = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = next;
        }
        return dummy->next;
    }
};
// @lc code=end
