// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-root-to-leaf-numbers
 *  RUNTIME: 7 ms
 *  MEMORY: 9.3 MB
 *  DATE: 1-15-2023, 7:14:33 PM
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
    
    void dfs(TreeNode* node, int num) {
        if(node == NULL) return;
        
        num = num*10 + node->val;
        if(node->left == NULL && node->right == NULL) ans += num;
        
        dfs(node->left, num);
        dfs(node->right, num);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
