/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode *root) {
        vector<TreeNode *> cur = {root};
        int sum = 0;
        while (cur.size() > 0) {
            vector<TreeNode *> nxt;
            sum = 0;
            for (auto node : cur) {
                if (node->left == node->right) {
                    sum += node->val;
                }
                if (node->left) {
                    nxt.push_back(node->left);
                }
                if (node->right) {
                    nxt.push_back(node->right);
                }
            }
            cur = move(nxt);
        }
        return sum;
    }
};
// @lc code=end
