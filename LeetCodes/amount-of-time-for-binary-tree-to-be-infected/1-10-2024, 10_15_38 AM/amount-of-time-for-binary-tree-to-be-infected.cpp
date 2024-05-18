// Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: amount-of-time-for-binary-tree-to-be-infected
 *  RUNTIME: 496 ms
 *  MEMORY: 185.9 MB
 *  DATE: 1-10-2024, 10:15:38 AM
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
    void dfs(TreeNode* node, unordered_map<int, vector<int>> &adj) {
        if(!node) return;

        if(node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            dfs(node->left, adj);
        }
        
        if(node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            dfs(node->right, adj);
        }
    }
    int bfs(int start, unordered_map<int, vector<int>> &adj) {
        int dist = 0;
        unordered_set<int> vis;
        queue<int> q;

        q.push(start);
        vis.insert(start);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();

                for(auto &next: adj[node]) {
                    if(!vis.count(next)) {
                        q.push(next);
                        vis.insert(next);
                    }
                }
            }
            dist++;
        }
        return dist - 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        dfs(root, adj);
        int time = bfs(start, adj);
        return time;
    }
};
