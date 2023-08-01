// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: lowest-common-ancestor-of-a-binary-search-tree
 *  RUNTIME: 35 ms
 *  MEMORY: 23.3 MB
 *  DATE: 1-17-2023, 5:18:14 PM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root; 
        if(p->val > root->val && q->val > root->val)    return lowestCommonAncestor(root->right ,p ,q);
        if(p->val < root->val && q->val < root->val)    return lowestCommonAncestor(root->left , p ,q);
        return root;
    }
};
