/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return (flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left));
    }
};
// @lc code=end
