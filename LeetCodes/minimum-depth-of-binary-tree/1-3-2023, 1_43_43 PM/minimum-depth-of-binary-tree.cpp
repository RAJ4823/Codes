// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-depth-of-binary-tree
 *  RUNTIME: 266 ms
 *  MEMORY: 144.9 MB
 *  DATE: 1-3-2023, 1:43:43 PM
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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        int minLevel = 0;

        while(!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node == NULL) continue;
            if(node->left == NULL && node->right == NULL) {
                minLevel = level;
                break;
            }
                
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        return minLevel;
    }
};
