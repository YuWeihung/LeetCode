/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include "tree_node.h"
#include <algorithm>
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
    // 通过全局变量 maxd 记录路径最大值
    int maxd = 0;
    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int l = depth(root->left);
            int r = depth(root->right);
            // 一棵树通过根节点的路径长度最大值为 l + r
            maxd = max(maxd, l + r);
            return max(l, r) + 1;
        }
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int d = depth(root);
            return maxd;
        }
    }
};
// @lc code=end
