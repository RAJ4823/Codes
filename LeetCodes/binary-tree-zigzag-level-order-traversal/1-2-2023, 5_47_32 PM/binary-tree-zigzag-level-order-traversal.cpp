// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-zigzag-level-order-traversal
 *  RUNTIME: 0 ms
 *  MEMORY: 12.2 MB
 *  DATE: 1-2-2023, 5:47:32 PM
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
    vector<int> rev(vector<int> &arr) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vis, ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node == NULL) continue;
            if(vis.size() <= level) {
                vis.push_back({node->val});
            } else {
                vis[level].push_back(node->val);
            }

            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }

        int n = vis.size();
        for(int i=1; i<n; i+=2) {
            vis[i] = rev(vis[i]);
        }
        return vis;
    }
};
