/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode *replaceValueInTree(TreeNode *root) {
        vector<TreeNode *> cur;
        cur.push_back(root);
        root->val = 0;
        while (!cur.empty()) {
            vector<TreeNode *> nxt;
            int next_sum = 0;
            for (auto node : cur) {
                if (node->left) {
                    nxt.push_back(node->left);
                    next_sum += node->left->val;
                }
                if (node->right) {
                    nxt.push_back(node->right);
                    next_sum += node->right->val;
                }
            }
            for (auto node : cur) {
                int children_sum =
                    (node->left ? node->left->val : 0) +
                    (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = next_sum - children_sum;
                }
                if (node->right) {
                    node->right->val = next_sum - children_sum;
                }
            }
            cur = move(nxt);
        }
        return root;
    }
};
// @lc code=end
