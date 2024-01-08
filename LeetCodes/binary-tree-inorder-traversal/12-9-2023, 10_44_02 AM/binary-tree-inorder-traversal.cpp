// Link: https://leetcode.com/problems/binary-tree-inorder-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-inorder-traversal
 *  RUNTIME: 0 ms
 *  MEMORY: 8.6 MB
 *  DATE: 12-9-2023, 10:44:02 AM
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
    void trav(TreeNode* node, vector<int> &ans) {
        if(node == NULL) return;
        trav(node->left, ans);
        ans.push_back(node->val);
        trav(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};
