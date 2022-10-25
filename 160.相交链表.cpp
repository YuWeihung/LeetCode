/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "list_node.h"

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
    /**
     * 主要思想是消除两个链表的长度差
     * 两个指针分别从 A B 的头结点开始遍历
     * pA 到达 A 链表末尾后指向 B 的头结点，pB 反之
     * 若两个链表相交，则 pA == pB 时即为相交的起始节点
     * 若不相交，最终 pA == pB == nullptr
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
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
