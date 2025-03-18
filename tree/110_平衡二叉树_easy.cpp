/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include "tree_node.h"
#include <algorithm>
#include <cmath>
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
    int get_height(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = get_height(node->left);
        if (left_height == -1) {
            return -1;
        }
        int right_height = get_height(node->right);
        if (right_height == -1 ||
            abs(right_height - left_height) > 1) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return get_height(root) != -1;
    }
};
// @lc code=end
