/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
 */
#include "tree_node.h"
#include <algorithm>
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
    vector<int> arr;

    void dfs(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        arr.push_back(node->val);
        dfs(node->right);
    }

    int lower_bound(vector<int> &nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<vector<int>> closestNodes(TreeNode *root,
                                     vector<int> &queries) {
        dfs(root);
        int n = arr.size();
        vector<vector<int>> ans;
        for (int q : queries) {
            int j = lower_bound(arr, q);
            int mx = j < n ? arr[j] : -1;
            if (j == n || arr[j] != q) {
                j--;
            }
            int mn = j >= 0 ? arr[j] : -1;
            ans.push_back({mn, mx});
        }
        return ans;
    }
};
// @lc code=end
