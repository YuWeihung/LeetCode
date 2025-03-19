/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val)
        : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root) {
        Node *dummy = new Node();
        Node *cur = root;
        while (cur) {
            dummy->next = nullptr;
            // 下一层的链表
            Node *nxt = dummy;
            while (cur) {
                if (cur->left) {
                    nxt->next = cur->left;
                    nxt = cur->left;
                }
                if (cur->right) {
                    nxt->next = cur->right;
                    nxt = cur->right;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};
// @lc code=end
