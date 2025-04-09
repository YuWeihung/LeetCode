/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode *root) {
        auto dfs = [&](auto &&dfs, TreeNode *node) -> pair<int, int> {
            if (node == nullptr) {
                return {0, 0};
            }
            auto [l_rob, l_not_rob] = dfs(dfs, node->left);
            auto [r_rob, r_not_rob] = dfs(dfs, node->right);
            int node_rob = l_not_rob + r_not_rob + node->val;
            int node_not_rob =
                max(l_rob, l_not_rob) + max(r_rob, r_not_rob);
            return {node_rob, node_not_rob};
        };
        auto [root_rob, root_not_rob] = dfs(dfs, root);
        return max(root_rob, root_not_rob);
    }
};
// @lc code=end
