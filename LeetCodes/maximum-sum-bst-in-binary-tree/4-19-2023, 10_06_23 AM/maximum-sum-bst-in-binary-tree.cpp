// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-sum-bst-in-binary-tree
 *  RUNTIME: 390 ms
 *  MEMORY: 224 MB
 *  DATE: 4-19-2023, 10:06:23 AM
 *
 */

// Solution:

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
    int maxSum = 0;
    vector<int> nullRootVector = {INT_MAX, INT_MIN, 0};
    vector<int> defaultVector = {INT_MIN, INT_MAX, 0};

    vector<int> dfs(TreeNode* root) {
        if(root == NULL) return nullRootVector;

        vector<int> left = dfs(root->left);
        vector<int> right= dfs(root->right);

        int val = root->val;
        // IF current tree is BST
        if(left[1] < val && val < right[0]) {
            int newSum = left[2] + right[2] + val;
            maxSum = max(maxSum, newSum);
            return {min(left[0], val), max(right[1], val), newSum};
        }
        return defaultVector;
    }
    int maxSumBST(TreeNode* root) {
        vector<int> ans = dfs(root);
        return maxSum;
    }
};
