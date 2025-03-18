/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */
#include "tree_node.h"
#include <algorithm>
#include <map>
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
    map<int, vector<pair<int, int>>> groups;

    void dfs(TreeNode *node, int row, int col) {
        if (node == nullptr) {
            return;
        }
        groups[col].emplace_back(row, node->val);
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto &[_, g] : groups) {
            sort(g.begin(), g.end());
            vector<int> vals;
            for (auto &[_, val] : g) {
                vals.push_back(val);
            }
            ans.push_back(vals);
        }
        return ans;
    }
};
// @lc code=end
