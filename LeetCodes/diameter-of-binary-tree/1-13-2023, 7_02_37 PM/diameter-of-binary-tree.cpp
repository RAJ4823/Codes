// Link: https://leetcode.com/problems/diameter-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: diameter-of-binary-tree
 *  RUNTIME: 13 ms
 *  MEMORY: 20.1 MB
 *  DATE: 1-13-2023, 7:02:37 PM
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
    int ans = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;

        int left = 0, right = 0, len = 0;

        left = dfs(root->left);
        right = dfs(root->right);
        len = max(left, right);
        ans = max(ans, max(len, left + right));
        return 1 + len;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
