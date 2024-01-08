// Link: https://leetcode.com/problems/construct-string-from-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: construct-string-from-binary-tree
 *  RUNTIME: 21 ms
 *  MEMORY: 26.4 MB
 *  DATE: 12-8-2023, 7:07:47 PM
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
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        if(root->left == NULL && root->right == NULL) return to_string(root->val);
        return to_string(root->val) + ("(" + tree2str(root->left) + ")") + ((root->right)? "(" + tree2str(root->right)+ ")": "");;
    }
};

