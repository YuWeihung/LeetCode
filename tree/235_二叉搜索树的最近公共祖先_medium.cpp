/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */
#include "tree_node.h"
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root,
                                   TreeNode *p,
                                   TreeNode *q) {
        int x = root->val;
        if (p->val < x && q->val < x) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > x && q->val > x) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
// @lc code=end
