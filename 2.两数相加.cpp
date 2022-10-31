/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include "list_node.h"

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        //  进位标志位
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            // 处理进位
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            // 分别处理头结点和后面结点
            if (head == nullptr) {
                head = new ListNode(sum);
                tail = head;
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            // 计算下一位
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        // 最高位进位
        if (carry != 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end
