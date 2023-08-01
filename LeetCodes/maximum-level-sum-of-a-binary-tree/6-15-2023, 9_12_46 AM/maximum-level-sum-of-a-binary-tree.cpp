// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-level-sum-of-a-binary-tree
 *  RUNTIME: 210 ms
 *  MEMORY: 107.3 MB
 *  DATE: 6-15-2023, 9:12:46 AM
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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, level = 1, maxLevel = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            while(size--) {
                auto node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelSum > maxSum) {
                maxLevel = level;
                maxSum = levelSum;
            }
            level++;
        }
        return maxLevel;
    }
};
