// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-depth-of-binary-tree
 *  RUNTIME: 13 ms
 *  MEMORY: 19.3 MB
 *  DATE: 1-2-2023, 6:10:09 PM
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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        int maxLevel = 0;

        while(!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node == NULL) continue;
            maxLevel = max(maxLevel, level);

            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        return maxLevel;
    }
};
