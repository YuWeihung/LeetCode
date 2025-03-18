/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include "tree_node.h"
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// vector 赋值 左闭右开区间

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
    unordered_map<int, int> index;

    TreeNode *dfs(vector<int> &preorder,
                  vector<int> &inorder,
                  int pre_l,
                  int pre_r,
                  int in_l,
                  int in_r) {
        if (pre_l == pre_r) {
            return nullptr;
        }
        int left_size = index[preorder[pre_l]] - in_l;
        TreeNode *left =
            dfs(preorder, inorder, pre_l + 1, pre_l + 1 + left_size,
                in_l, in_l + left_size);
        TreeNode *right =
            dfs(preorder, inorder, pre_l + 1 + left_size, pre_r,
                in_l + 1 + left_size, in_r);
        return new TreeNode(preorder[pre_l], left, right);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n, 0, n);
    }
};
// @lc code=end
