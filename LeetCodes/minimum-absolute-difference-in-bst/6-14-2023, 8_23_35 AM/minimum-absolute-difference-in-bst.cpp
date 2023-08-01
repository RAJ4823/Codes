// Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-absolute-difference-in-bst
 *  RUNTIME: 16 ms
 *  MEMORY: 25.1 MB
 *  DATE: 6-14-2023, 8:23:35 AM
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
    int minDiff = INT_MAX;
    int prev = -1, curr = -1;
    void trav(TreeNode* node) {
        if(node == NULL) return;
        trav(node->left);
        if(prev == -1) {
            prev = node->val;
        } 
        else if(curr == -1) {
            curr = node->val;
            minDiff = min(minDiff, abs(prev - curr));
        } 
        else {
            prev = curr;
            curr = node->val;
            minDiff = min(minDiff, abs(prev - curr));
        }
        trav(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* temp = NULL;
        trav(root);
        return minDiff;
    }
};
