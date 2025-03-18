/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */
#include "tree_node.h"
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
    int ans, k;
    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }
};
// @lc code=end
