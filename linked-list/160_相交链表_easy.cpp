/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "list_node.h"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        if (pA == nullptr || pB == nullptr) {
            return nullptr;
        }
        while (pA != pB) {
            if (pA != nullptr) {
                pA = pA->next;
            } else {
                pA = headB;
            }
            if (pB != nullptr) {
                pB = pB->next;
            } else {
                pB = headA;
            }
        }
        return pA;
    }
};
// @lc code=end
