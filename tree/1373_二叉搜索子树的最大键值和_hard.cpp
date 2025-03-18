/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */
#include "tree_node.h"
#include <algorithm>
#include <climits>
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
    int ans = 0; // 二叉搜索树可以为空

    tuple<int, int, int> dfs(TreeNode *node) {
        if (node == nullptr)
            return {INT_MAX, INT_MIN, 0};

        auto [l_min, l_max, l_sum] = dfs(node->left);  // 递归左子树
        auto [r_min, r_max, r_sum] = dfs(node->right); // 递归右子树
        int x = node->val;
        if (x <= l_max || x >= r_min) // 不是二叉搜索树
            return {INT_MIN, INT_MAX, 0};

        int s = l_sum + r_sum + x; // 这棵子树的所有节点值之和
        ans = max(ans, s);

        return {min(l_min, x), max(r_max, x), s};
    }

public:
    int maxSumBST(TreeNode *root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end
