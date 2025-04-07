/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include "tree_node.h"
#include <algorithm>
#include <climits>
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
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        auto dfs = [&](auto &&dfs, TreeNode *node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int l_val = dfs(dfs, node->left);
            int r_val = dfs(dfs, node->right);
            ans = max(ans, l_val + r_val + node->val);
            return max(0, max(l_val, r_val) + node->val);
        };
        dfs(dfs, root);
        return ans;
    }
};
// @lc code=end
