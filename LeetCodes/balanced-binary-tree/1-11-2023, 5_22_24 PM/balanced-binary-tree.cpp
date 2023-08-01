// Link: https://leetcode.com/problems/balanced-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: balanced-binary-tree
 *  RUNTIME: 13 ms
 *  MEMORY: 21 MB
 *  DATE: 1-11-2023, 5:22:24 PM
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
    int dfs(TreeNode* node, bool &ans) {
        if(node == NULL) return 0;
        if(ans == false) return 0;
        int depthOfLeftTree = 1 + dfs(node->left, ans);
        int depthOfRightTree = 1 + dfs(node->right, ans);
        if(abs(depthOfLeftTree - depthOfRightTree) > 1) {
            ans = false;
        }
        return max(depthOfLeftTree, depthOfRightTree);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};
