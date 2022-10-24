/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include "tree_node.h"
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 通过队列实现广度优先搜索
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        // 通过 pair 同时存储节点和深度信息
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                q.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};
// @lc code=end
