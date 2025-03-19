/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */
#include "tree_node.h"
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

    TreeNode *dfs(vector<int> &preorder,
                  vector<int> &postorder,
                  int pre_l,
                  int pre_r,
                  int post_l) {
        // 空节点
        if (pre_l == pre_r) {
            return nullptr;
        }
        // 叶子节点
        if (pre_l + 1 == pre_r) {
            return new TreeNode(preorder[pre_l]);
        }
        int left_size = index[preorder[pre_l + 1]] - post_l + 1;
        TreeNode *left = dfs(preorder, postorder, pre_l + 1,
                             pre_l + 1 + left_size, post_l);
        TreeNode *right =
            dfs(preorder, postorder, pre_l + 1 + left_size, pre_r,
                post_l + left_size);
        return new TreeNode(preorder[pre_l], left, right);
    }

    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[postorder[i]] = i;
        }
        return dfs(preorder, postorder, 0, n, 0);
    }
};
// @lc code=end
