// Link: https://leetcode.com/problems/recover-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: recover-binary-search-tree
 *  RUNTIME: 43 ms
 *  MEMORY: 57.7 MB
 *  DATE: 1-11-2023, 6:26:47 PM
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
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    TreeNode* prev = NULL;

    void inOrder(TreeNode* root) {
        if(root == NULL) return;

        inOrder(root->left);
        if(prev != NULL) {
            if(node1 == NULL && prev->val >= root->val)  node1 = prev;
            if(node1 != NULL && prev->val >= root->val)  node2 = root;
        }
        prev = root;
        inOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inOrder(root);

        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
