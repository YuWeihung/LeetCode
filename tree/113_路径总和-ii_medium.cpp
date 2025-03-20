/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include "tree_node.h"
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
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int target, int cur, vector<int> &path) {
        if (root == nullptr) {
            return;
        }
        cur += root->val;
        path.push_back(root->val);
        if (root->left == root->right) {
            if (cur == target) {
                ans.push_back(path);
            }
        } else {
            dfs(root->left, target, cur, path);
            dfs(root->right, target, cur, path);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, 0, path);
        return ans;
    }
};
// @lc code=end
