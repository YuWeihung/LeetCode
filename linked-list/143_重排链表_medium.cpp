/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void reorderList(ListNode *head) {
        ListNode *mid = middleNode(head);
        ListNode *head2 = reverseList(mid);
        while (head2->next != nullptr) {
            ListNode *next = head->next;
            ListNode *next2 = head2->next;
            head->next = head2;
            head2->next = next;
            head = next;
            head2 = next2;
        }
    }
};
// @lc code=end
