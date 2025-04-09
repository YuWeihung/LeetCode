/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
#include "tree_node.h"
#include <algorithm>
#include <climits>
#include <vector>
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
    int minCameraCover(TreeNode *root) {
        auto dfs = [&](auto &&dfs,
                       TreeNode *node) -> tuple<int, int, int> {
            if (node == nullptr) {
                return {INT_MAX / 2, 0, 0};
            }
            auto [l_choose, l_by_fa, l_by_children] =
                dfs(dfs, node->left);
            auto [r_choose, r_by_fa, r_by_children] =
                dfs(dfs, node->right);
            int choose =
                min(l_choose, l_by_fa) + min(r_choose, r_by_fa) + 1;
            int by_fa = min(l_choose, l_by_children) +
                        min(r_choose, r_by_children);
            int by_children =
                min({l_choose + r_by_children,
                     l_by_children + r_choose, l_choose + r_choose});
            return {choose, by_fa, by_children};
        };
        auto [choose, _, by_children] = dfs(dfs, root);
        return min(choose, by_children);
    }
};
// @lc code=end
