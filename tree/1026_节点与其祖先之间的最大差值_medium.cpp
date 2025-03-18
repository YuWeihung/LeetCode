/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans = 0;

    void dfs(TreeNode *node, int minn, int maxn) {
        if (node == nullptr) {
            return;
        }
        minn = min(minn, node->val);
        maxn = max(maxn, node->val);
        ans = max(ans, max(maxn - node->val, node->val - minn));
        dfs(node->left, minn, maxn);
        dfs(node->right, minn, maxn);
    }

    int maxAncestorDiff(TreeNode *root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
// @lc code=end
