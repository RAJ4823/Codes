// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: all-nodes-distance-k-in-binary-tree
 *  RUNTIME: 0 ms
 *  MEMORY: 12.6 MB
 *  DATE: 7-11-2023, 12:56:13 PM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs_fill(TreeNode* node) {
        if(node == NULL) return;

        if(node->left)  parent[node->left]= node;
        if(node->right) parent[node->right]= node;
        
        dfs_fill(node->left);
        dfs_fill(node->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs_fill(root);
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({target, target});
        vector<int> ans;
        int dist = 0;

        while(!q.empty()) {
            int size = q.size();
            if(dist > k) break;
            
            while(size--) {
                auto node = q.front().first;
                auto par = q.front().second;
                q.pop();

                if(dist == k) {
                    ans.push_back(node->val);
                    continue;
                }
                
                if(node->left && node->left != par) {
                    q.push({node->left, node});
                }
                if(node->right && node->right != par) {
                    q.push({node->right, node});
                }
                if(parent[node] && parent[node] != par) {
                    q.push({parent[node], node});
                }
            } 
            dist++;
        }
        return ans;
    }
};
