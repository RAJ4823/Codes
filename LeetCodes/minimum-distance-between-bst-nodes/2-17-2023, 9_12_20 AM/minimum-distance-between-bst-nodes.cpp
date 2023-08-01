// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-distance-between-bst-nodes
 *  RUNTIME: 0 ms
 *  MEMORY: 9.8 MB
 *  DATE: 2-17-2023, 9:12:20 AM
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
    int minDiff = INT_MAX;
    int prevVal = -1;
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;

        dfs(root -> left);
        if (prevVal != -1) minDiff = min(minDiff, root -> val - prevVal);
        prevVal = root -> val;
        dfs(root -> right);
        
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minDiff;
    }
};
