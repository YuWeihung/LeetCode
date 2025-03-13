/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode *doubleIt(ListNode *head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        ListNode *cur = head;
        while (cur != nullptr) {
            cur->val = (cur->val * 2) % 10;
            if (cur->next && cur->next->val > 4) {
                cur->val++;
            }
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
