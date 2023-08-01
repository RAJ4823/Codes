// Link: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: second-minimum-node-in-a-binary-tree
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 1-16-2023, 1:23:29 PM
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
    int min2 = -1;
    void dfs(TreeNode* root, int min1){
        if(root == NULL) return;

        if(root->val > min1) {
            if(min2 == -1) min2 = root->val;
            else if(root->val <= min2) {
                min2 = root->val;
                return;
            }
        }

        dfs(root->left, min1);
        dfs(root->right, min1); 
    }

    int findSecondMinimumValue(TreeNode* root) {
        int min1 = root->val;
        dfs(root, min1);
        return min2;
    }
};
