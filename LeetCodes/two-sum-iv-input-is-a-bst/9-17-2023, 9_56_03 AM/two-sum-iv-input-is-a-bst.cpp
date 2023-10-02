// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: two-sum-iv-input-is-a-bst
 *  RUNTIME: 41 ms
 *  MEMORY: 39.4 MB
 *  DATE: 9-17-2023, 9:56:03 AM
 *
 */

// Solution:

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if(root == NULL)
            return false;
        if(set.count(k - root->val))
            return true;
        
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }
};

