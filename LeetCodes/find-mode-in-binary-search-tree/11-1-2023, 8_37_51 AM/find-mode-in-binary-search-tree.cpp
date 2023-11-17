// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-mode-in-binary-search-tree
 *  RUNTIME: 4 ms
 *  MEMORY: 24.3 MB
 *  DATE: 11-1-2023, 8:37:51 AM
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
    int val = INT_MIN, freq = 0, maxFreq = 0;
    vector<int> ans;
    void find(TreeNode* node) {
        if(!node) return;
        
        find(node->left);

        if(node->val == val) 
            freq++;
        else
            freq = 1, val = node->val;
        
        if(freq > maxFreq)
            ans = {node->val}, maxFreq = freq;
        else if(freq == maxFreq)
            ans.push_back(node->val);

        find(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        find(root);
        return ans;
    }
};
