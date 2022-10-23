/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 迭代解法，用队列替代递归
    bool check(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        que.push(q);
        que.push(p);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if (p == nullptr && q == nullptr) {
                continue;
            } else if (p == nullptr || q == nullptr) {
                return false;
            } else if (p->val != q->val) {
                return false;
            } else {
                que.push(p->left);
                que.push(q->right);
                que.push(p->right);
                que.push(q->left);
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode *root) {
        return check(root, root);
    }
};
// @lc code=end
