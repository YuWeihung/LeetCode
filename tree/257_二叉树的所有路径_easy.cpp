/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include "tree_node.h"
#include <iostream>
#include <string>
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
    vector<string> ans;
    void dfs(TreeNode *node, string path) {
        if (node == nullptr) {
            return;
        }
        path += to_string(node->val);
        if (node->left == node->right) {
            ans.push_back(path);
            return;
        }
        path += "->";
        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        dfs(root, "");
        return ans;
    }
};
// @lc code=end
