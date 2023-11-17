// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-largest-value-in-each-tree-row
 *  RUNTIME: 4 ms
 *  MEMORY: 22.6 MB
 *  DATE: 10-24-2023, 3:54:18 PM
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> row;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;
            while(size--) {
                auto node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            row.push_back(maxVal);
        }
        return row;
    }
};
