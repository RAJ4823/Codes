// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-level-order-traversal-ii
 *  RUNTIME: 12 ms
 *  MEMORY: 12.6 MB
 *  DATE: 1-3-2023, 1:23:31 PM
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node == NULL) continue;
            
            if(ans.size() <= level)
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);

            
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
