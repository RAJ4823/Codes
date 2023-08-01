// Link: https://leetcode.com/problems/symmetric-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: symmetric-tree
 *  RUNTIME: 3 ms
 *  MEMORY: 16.4 MB
 *  DATE: 12-31-2022, 8:34:59 PM
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
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val)  return false;
        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirrorTree(root->left, root->right);
    }
};
