/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include "tree_node.h"
#include <algorithm>
#include <unordered_map>
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
    unordered_map<int, int> index;

    TreeNode *dfs(vector<int> &inorder,
                  vector<int> &postorder,
                  int in_l,
                  int in_r,
                  int post_l,
                  int post_r) {
        if (post_l == post_r) { // 空节点
            return nullptr;
        }
        int left_size =
            index[postorder[post_r - 1]] - in_l; // 左子树的大小
        TreeNode *left =
            dfs(inorder, postorder, in_l, in_l + left_size, post_l,
                post_l + left_size);
        TreeNode *right =
            dfs(inorder, postorder, in_l + left_size + 1, in_r,
                post_l + left_size, post_r - 1);
        return new TreeNode(postorder[post_r - 1], left, right);
    }

    TreeNode *buildTree(vector<int> &inorder,
                        vector<int> &postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return dfs(inorder, postorder, 0, n, 0, n);
    }
};
// @lc code=end
