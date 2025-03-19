/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include "tree_node.h"
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(vals);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
