/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 递归合并二叉树
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) {
            return root2;
        } else if (root2 == nullptr) {
            return root1;
        } else {
            auto merged = new TreeNode(root1->val + root2->val);
            merged->left = mergeTrees(root1->left, root2->left);
            merged->right = mergeTrees(root1->right, root2->right);
            return merged;
        }
    }
};
// @lc code=end
