// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-smallest-element-in-a-bst
 *  RUNTIME: 12 ms
 *  MEMORY: 24.1 MB
 *  DATE: 1-16-2023, 12:53:58 PM
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
    int count = 0, ans, K;
    void dfs(TreeNode* root) {
        if(root == NULL) return;

        dfs(root->left);
        count++;
        if(count == K)  ans = root->val;
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        dfs(root);
        return ans;
    }
};
