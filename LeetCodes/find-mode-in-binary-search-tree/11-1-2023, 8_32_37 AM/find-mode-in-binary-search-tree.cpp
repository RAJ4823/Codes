// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-mode-in-binary-search-tree
 *  RUNTIME: 19 ms
 *  MEMORY: 25.5 MB
 *  DATE: 11-1-2023, 8:32:37 AM
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
    unordered_map<int,int> cnt;
    int maxFreq = 0;
    void find(TreeNode* node) {
        if(!node) return;
        
        cnt[node->val]++;
        maxFreq = max(maxFreq, cnt[node->val]);
        find(node->left);
        find(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        find(root);
        vector<int> ans;
        for(auto &[val, freq]: cnt) {
            if(freq == maxFreq)
                ans.push_back(val);
        }
        return ans;
    }
};
