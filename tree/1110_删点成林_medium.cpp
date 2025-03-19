/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */
#include "tree_node.h"
#include <unordered_set>
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
    vector<TreeNode *> ans;
    unordered_set<int> st;

    TreeNode *dfs(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = dfs(root->left);
        root->right = dfs(root->right);

        // 要删除
        if (st.count(root->val)) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        } else {
            return root;
        }
    }

    vector<TreeNode *> delNodes(TreeNode *root,
                                vector<int> &to_delete) {
        for (int i = 0; i < to_delete.size(); i++) {
            st.insert(to_delete[i]);
        }
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};
// @lc code=end
