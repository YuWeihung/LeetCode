/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_depth = -1;
    TreeNode *ans = nullptr;

    int dfs(TreeNode *node, int depth) {
        if (node == nullptr) {
            max_depth = max(max_depth, depth);
            return depth;
        }
        int left_max_depth = dfs(node->left, depth + 1);
        int right_max_depth = dfs(node->right, depth + 1);
        if (left_max_depth == right_max_depth &&
            left_max_depth == max_depth) {
            ans = node;
        }
        return max(left_max_depth, right_max_depth);
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end
