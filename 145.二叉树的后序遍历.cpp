/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include "tree_node.h"
#include <stack>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 迭代法后序遍历二叉树
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        // 记录上次访问的结点
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            // 如果右子树为空或刚访问完，访问根节点并出栈；否则访问右子树
            // 每访问完一个结点都需要将指针置为 null
            if (root->right == nullptr || root->right == prev) {
                stk.pop();
                result.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return result;
    }
};
// @lc code=end
