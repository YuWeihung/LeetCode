/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        limit -= root->val;
        if (root->left == root->right) {
            if (limit > 0) {
                return nullptr;
            } else {
                return root;
            }
        }
        if (root->left) {
            root->left = sufficientSubset(root->left, limit);
        }
        if (root->right) {
            root->right = sufficientSubset(root->right, limit);
        }
        if (root->left || root->right) {
            return root;
        } else {
            return nullptr;
        }
    }
};
// @lc code=end
