// Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-zigzag-path-in-a-binary-tree
 *  RUNTIME: 164 ms
 *  MEMORY: 94.2 MB
 *  DATE: 4-19-2023, 9:50:22 AM
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
    // dir - 0 : left
    // dir - 1 : right
    void dfs(TreeNode* node, int dir, int len) {
        if(node == NULL) {
            maxLen = max(maxLen, len-1);
            return;
        }

        
        if(dir == 0) {
            dfs(node->left, 0, 1);
            dfs(node->right,1, len+1);
            maxLen = max(maxLen, len-1);
        } else {
            dfs(node->left, 0, len+1);
            dfs(node->right,1, 1);
            maxLen = max(maxLen, len-1);
        }
        return;
    } 
    int longestZigZag(TreeNode* root) {
        if(root->left != NULL) dfs(root->left, 0, 1);
        if(root->right!= NULL) dfs(root->right,1, 1);
        return maxLen;
    }
};
