/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 */
#include "tree_node.h"
#include <algorithm>
#include <queue>
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
    TreeNode *reverseOddLevels(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        int depth = 0;
        vector<TreeNode *> cur_depth = {root};
        while (cur_depth[0]->left) {
            vector<TreeNode *> next_depth;
            for (TreeNode *node : cur_depth) {
                next_depth.push_back(node->left);
                next_depth.push_back(node->right);
            }
            if (depth % 2 == 0) {
                int n = next_depth.size();
                for (int i = 0; i < n / 2; i++) {
                    TreeNode *x = next_depth[i];
                    TreeNode *y = next_depth[n - i - 1];
                    swap(x->val, y->val);
                }
            }
            cur_depth = move(next_depth);
            depth++;
        }
        return root;
    }
};
// @lc code=end
