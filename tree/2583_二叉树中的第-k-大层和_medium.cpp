/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
 */
#include "tree_node.h"
#include <algorithm>
#include <iostream>
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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        vector<TreeNode *> cur = {root};
        vector<long long> sums;
        while (cur.size()) {
            long long sum = 0;
            vector<TreeNode *> nxt;
            for (auto node : cur) {
                sum += node->val;
                if (node->left) {
                    nxt.push_back(node->left);
                }
                if (node->right) {
                    nxt.push_back(node->right);
                }
            }
            cur = move(nxt);
            sums.push_back(sum);
        }
        if (k > sums.size()) {
            return -1;
        }
        int n = sums.size();
        nth_element(sums.begin(), sums.begin() + n - k, sums.end());
        return sums[n - k];
    }
};
// @lc code=end
