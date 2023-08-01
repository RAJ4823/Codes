// Link: https://leetcode.com/problems/validate-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: validate-binary-search-tree
 *  RUNTIME: 11 ms
 *  MEMORY: 21.8 MB
 *  DATE: 1-11-2023, 5:52:07 PM
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
     bool check(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (check(node->left, prev) == false) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return check(node->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return check(root, prev);
    }
};
