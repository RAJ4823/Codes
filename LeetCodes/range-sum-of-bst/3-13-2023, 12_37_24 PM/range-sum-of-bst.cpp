// Link: https://leetcode.com/problems/range-sum-of-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: range-sum-of-bst
 *  RUNTIME: 114 ms
 *  MEMORY: 64.7 MB
 *  DATE: 3-13-2023, 12:37:24 PM
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
    int findSum(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int sum = 0;
        if(root->val >= low && root->val <= high) sum += root->val;
        sum += findSum(root->right, low, high);
        sum += findSum(root->left, low, high);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};
