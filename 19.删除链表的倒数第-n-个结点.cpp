/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 双指针
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 哑结点，它的后继为头结点
        auto dummy = new ListNode(0, head);
        auto fast = head;
        auto slow = dummy;
        // fast 指针领先 slow 指针 n + 1 个位置
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // 当 fast 到达链表尾时，slow 正好到达倒数第 n 个结点的前驱
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        // dummy 的后继是头结点
        return dummy->next;
    }
};
// @lc code=end
