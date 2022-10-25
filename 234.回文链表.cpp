/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include "list_node.h"
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
    // 寻找中间结点，如果总数为奇数，中间算到前半部分
    ListNode *findMid(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 迭代法反转链表
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }
        auto mid = findMid(head);
        // 将后半部分反转
        auto secondHead = reverseList(mid->next);
        auto p1 = head;
        auto p2 = secondHead;
        bool ret = true;
        // 对比两部分是否相等
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val != p2->val) {
                ret = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表
        mid->next = reverseList(secondHead);
        return ret;
    }
};
// @lc code=end
