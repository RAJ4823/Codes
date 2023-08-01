// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: lowest-common-ancestor-of-a-binary-tree
 *  RUNTIME: 17 ms
 *  MEMORY: 14.1 MB
 *  DATE: 4-20-2023, 11:45:11 AM
 *
 */

// Solution:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left && right)
            return root;
        if(left)
            return left;
        return right;
    }
};
