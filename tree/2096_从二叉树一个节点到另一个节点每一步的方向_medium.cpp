/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 */
#include "tree_node.h"
#include <string>
#include <unordered_map>
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
    string path = "";

    bool dfs(TreeNode *node, int target) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == target) {
            return true;
        }
        path.push_back('L');
        if (dfs(node->left, target)) {
            return true;
        }
        path.back() = 'R';
        if (dfs(node->right, target)) {
            return true;
        }
        path = path.substr(0, path.length() - 1);
        return false;
    }

    string
        getDirections(TreeNode *root, int startValue, int destValue) {
        dfs(root, startValue);
        string path_to_start = path;
        path = "";
        dfs(root, destValue);
        string path_to_dest = path;
        int k = 0;
        while (!path_to_start.empty() && !path_to_dest.empty() &&
               path_to_start[k] == path_to_dest[k]) {
            k++;
        }
        path_to_start =
            path_to_start.substr(k, path_to_start.length() - k);
        path_to_dest =
            path_to_dest.substr(k, path_to_dest.length() - k);
        for (int i = 0; i < path_to_start.length(); i++) {
            path_to_start[i] = 'U';
        }
        string ans = path_to_start.append(path_to_dest);
        return ans;
    }
};
// @lc code=end
