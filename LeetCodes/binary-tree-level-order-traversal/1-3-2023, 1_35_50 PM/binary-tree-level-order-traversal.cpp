// Link: https://leetcode.com/problems/binary-tree-level-order-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-level-order-traversal
 *  RUNTIME: 15 ms
 *  MEMORY: 13.5 MB
 *  DATE: 1-3-2023, 1:35:50 PM
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
    void dfs(TreeNode* root, int level, vector<vector<int>> &ans)
    {
        if (root == NULL) return;
        if (ans.size() <= level)
            ans.push_back({root->val});
        else
            ans[level].push_back(root->val);

        dfs(root->left, level+1, ans);
        dfs(root->right,level+1, ans);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
