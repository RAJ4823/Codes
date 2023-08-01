// Link: https://leetcode.com/problems/path-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-sum
 *  RUNTIME: 23 ms
 *  MEMORY: 21.7 MB
 *  DATE: 1-3-2023, 1:47:20 PM
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto node = q.front().first;
            int pathSum = q.front().second;
            q.pop();

            if(node == NULL) continue;
            if(node->left == NULL && node->right == NULL) {
                if(pathSum + node->val == targetSum) 
                    return true;
            }
                
            q.push({node->left, pathSum + node->val});
            q.push({node->right, pathSum + node->val});
        }
        return false;
    }
};
