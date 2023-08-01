// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-depth-of-binary-tree
 *  RUNTIME: 10 ms
 *  MEMORY: 18.8 MB
 *  DATE: 2-16-2023, 8:54:31 AM
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
    int maxLen = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(dfs(root->right), dfs(root->left));

    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
