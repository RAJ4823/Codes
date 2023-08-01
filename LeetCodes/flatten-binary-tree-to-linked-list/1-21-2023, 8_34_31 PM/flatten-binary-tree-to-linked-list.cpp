// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flatten-binary-tree-to-linked-list
 *  RUNTIME: 13 ms
 *  MEMORY: 12.7 MB
 *  DATE: 1-21-2023, 8:34:31 PM
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
    TreeNode* lastRight(TreeNode* root) {
        if(root->right == NULL) return root;
        return lastRight(root->right);
    }
  
    void flatten(TreeNode* root) {
        if (root==NULL) return;
        TreeNode* rightChild;
        TreeNode* lastRightChild;
        
        while (root){
            if (root->left){
                lastRightChild = lastRight(root->left);
                rightChild = root->right;

                root->right = root->left;
                root->left = NULL;
                lastRightChild->right=rightChild;
            }
            root=root->right;
        }
    }
};
