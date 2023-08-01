// Link: https://leetcode.com/problems/sum-of-left-leaves

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-left-leaves
 *  RUNTIME: 20 ms
 *  MEMORY: 13.5 MB
 *  DATE: 1-6-2023, 5:12:59 PM
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node->left != NULL) {
                if(node->left->left == NULL && node->left->right == NULL)
                    sum += node->left->val;
                q.push(node->left);  
            }
            if(node->right != NULL) {
                q.push(node->right);
            }
        }
        return sum;
    }
};
