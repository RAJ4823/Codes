// Link: https://leetcode.com/problems/binary-tree-right-side-view

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-right-side-view
 *  RUNTIME: 3 ms
 *  MEMORY: 12 MB
 *  DATE: 1-4-2023, 5:47:13 PM
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<int> ans;
        int index = 0;

        while(!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(ans.size() == level) ans.push_back(node->val);
            else                    ans[level] = node->val;

            if(node->left != NULL) q.push({node->left, level + 1});
            if(node->right != NULL) q.push({node->right, level + 1});
        }
        return ans;
    }
};
