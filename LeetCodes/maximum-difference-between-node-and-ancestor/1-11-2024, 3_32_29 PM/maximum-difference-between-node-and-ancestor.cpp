// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-difference-between-node-and-ancestor
 *  RUNTIME: 8 ms
 *  MEMORY: 11.2 MB
 *  DATE: 1-11-2024, 3:32:29 PM
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
    int ans = 0;
    void find(TreeNode* node, int mini, int maxi) {
        if(!node) return;

        mini = min(mini, node->val);
        maxi = max(maxi, node->val);
        ans = max({ans, maxi - node->val, node->val - mini});
        
        find(node->left, mini, maxi);
        find(node->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        find(root, INT_MAX, INT_MIN);
        return ans;
    }
};
