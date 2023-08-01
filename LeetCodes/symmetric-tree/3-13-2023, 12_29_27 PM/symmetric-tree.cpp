// Link: https://leetcode.com/problems/symmetric-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: symmetric-tree
 *  RUNTIME: 11 ms
 *  MEMORY: 16.4 MB
 *  DATE: 3-13-2023, 12:29:27 PM
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
private: 
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL || p->val != q->val) return false;
        return (isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirrorTree(root->left, root->right);
    }
};
