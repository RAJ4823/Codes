// Link: https://leetcode.com/problems/binary-tree-level-order-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-level-order-traversal
 *  RUNTIME: 0 ms
 *  MEMORY: 12.6 MB
 *  DATE: 12-31-2022, 8:53:50 PM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<pair<TreeNode*,int>> treeQ;
        vector<vector<int>> ans;
        treeQ.push({root, 0});

        while(!treeQ.empty()) {
            auto node = treeQ.front().first;
            int level = treeQ.front().second;
            treeQ.pop();

            if(node == NULL) continue;
            
            if(ans.size() <= level)
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);

            
            treeQ.push({node->left, level + 1});
            treeQ.push({node->right, level + 1});
        }
        return ans;
    }
};
