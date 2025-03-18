/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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

    void dfs(TreeNode *root, int maxn) {
        if (root == nullptr) {
            return;
        }
        maxn = max(maxn, root->val);
        if (maxn == root->val) {
            ans++;
        }
        dfs(root->left, maxn);
        dfs(root->right, maxn);
    }
    int goodNodes(TreeNode *root) {
        int maxn = -0x3f3f3f3f;
        dfs(root, maxn);
        return ans;
    }
};
// @lc code=end
