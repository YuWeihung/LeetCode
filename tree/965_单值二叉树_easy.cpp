/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 */
#include "tree_node.h"
#include <iostream>

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
    bool flag = true;
    void dfs(TreeNode *node, int val) {
        if (node == nullptr) {
            return;
        }
        if (node->val != val) {
            flag = false;
            return;
        }
        dfs(node->left, val);
        dfs(node->right, val);
    }

    bool isUnivalTree(TreeNode *root) {
        dfs(root, root->val);
        return flag;
    }
};
// @lc code=end
