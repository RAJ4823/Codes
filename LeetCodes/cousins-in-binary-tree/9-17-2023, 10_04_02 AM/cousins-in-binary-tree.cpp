// Link: https://leetcode.com/problems/cousins-in-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: cousins-in-binary-tree
 *  RUNTIME: 6 ms
 *  MEMORY: 11.1 MB
 *  DATE: 9-17-2023, 10:04:02 AM
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
    int parx = -1, levx = -1, pary = -1, levy = -1;
    int x, y;
    bool isValid() {
        if(parx == -1 || pary == -1) return false;
        if(parx == pary) return false;
        if(levx != levy) return false;
        return true;
    }
    bool dfs(TreeNode* root, int par, int lev) {
        if(root == NULL) return false;

        if(root->val == x) {
            parx = par;
            levx = lev;
        }
        if(root->val == y) {
            pary = par;
            levy = lev;
        }

        if(isValid())
            return true;
        return dfs(root->left, root->val, lev+1) || dfs(root->right, root->val, lev+1);
    }
    bool isCousins(TreeNode* root, int X, int Y) {
        x = X;
        y = Y;
        return dfs(root, 0, 0);
    }
};
