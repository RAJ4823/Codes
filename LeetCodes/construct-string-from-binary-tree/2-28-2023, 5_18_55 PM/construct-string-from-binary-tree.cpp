// Link: https://leetcode.com/problems/construct-string-from-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: construct-string-from-binary-tree
 *  RUNTIME: 31 ms
 *  MEMORY: 54 MB
 *  DATE: 2-28-2023, 5:18:55 PM
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
        
        string leftSubtree = "(" + tree2str(root->left) + ")";
        string rightSubtree= (root->right)? "(" + tree2str(root->right)+ ")": "";

        string s = to_string(root->val) + leftSubtree + rightSubtree;
        return s;
    }
};

