// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-maximum-path-sum
 *  RUNTIME: 43 ms
 *  MEMORY: 27.6 MB
 *  DATE: 1-21-2023, 8:55:52 PM
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
    int maxPath = INT_MIN;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int diameter = left + right + root->val;
        maxPath = max(maxPath, diameter);
        int maxLen = max(left, right) + root->val;
        if(maxLen < 0) maxLen = 0;
        return maxLen;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};
