// Link: https://leetcode.com/problems/count-complete-tree-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-complete-tree-nodes
 *  RUNTIME: 42 ms
 *  MEMORY: 31 MB
 *  DATE: 1-15-2023, 7:26:45 PM
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
     int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        int left = 1, right = 1;
        
        TreeNode *subr = root;
        TreeNode *subl = root;
        while (subl = subl->left) left++;
        while (subr = subr->right) right++;
        
        if (left == right) return pow(2, left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
