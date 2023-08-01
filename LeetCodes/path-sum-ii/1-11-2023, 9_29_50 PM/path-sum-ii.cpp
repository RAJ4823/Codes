// Link: https://leetcode.com/problems/path-sum-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-sum-ii
 *  RUNTIME: 34 ms
 *  MEMORY: 35.7 MB
 *  DATE: 1-11-2023, 9:29:50 PM
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
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        if(root == NULL) return {};

        int count = 0;
        vector<vector<int>> paths;

        queue<pair<TreeNode*, pair<int, vector<int> >>> q;
        q.push({root, {root->val, {root->val} }});

        while(!q.empty()) {
            auto node = q.front().first;
            int pathSum = q.front().second.first;
            vector<int> path = q.front().second.second;
            q.pop();

            if(node->left == NULL && node->right == NULL && pathSum == tar) {
                paths.push_back(path);
            }
        
            if(node->left != NULL) {
                int newSum = pathSum + node->left->val;
                path.push_back(node->left->val);

                q.push({node->left, {newSum, path}});
                path.pop_back();
            } 
            if(node->right != NULL) {
                int newSum = pathSum + node->right->val;
                path.push_back(node->right->val);

                q.push({node->right, {newSum, path}});
                path.pop_back();
            }         
        }
        return paths;
    }
};
