// Link: https://leetcode.com/problems/binary-tree-preorder-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-preorder-traversal
 *  RUNTIME: 0 ms
 *  MEMORY: 8.5 MB
 *  DATE: 1-9-2023, 5:11:13 PM
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
        ans.push_back(node->val);
        trav(node->left, ans);
        trav(node->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};
