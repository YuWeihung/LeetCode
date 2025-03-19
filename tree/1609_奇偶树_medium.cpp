/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 */
#include "tree_node.h"
#include <climits>
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
    bool isEvenOddTree(TreeNode *root) {
        int level = 0;
        vector<TreeNode *> cur = {root};
        while (!cur.empty()) {
            vector<TreeNode *> nxt;
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (auto node : cur) {
                int x = node->val;
                if (level % 2 == 0) {
                    if (x % 2 == 0 || x <= prev) {
                        return false;
                    }
                }
                if (level % 2 == 1) {
                    if (x % 2 == 1 || x >= prev) {
                        return false;
                    }
                }
                prev = x;
                if (node->left) {
                    nxt.push_back(node->left);
                }
                if (node->right) {
                    nxt.push_back(node->right);
                }
            }
            level++;
            cur = move(nxt);
        }
        return true;
    }
};
// @lc code=end
