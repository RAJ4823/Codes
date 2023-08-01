// Link: https://leetcode.com/problems/invert-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: invert-binary-tree
 *  RUNTIME: 3 ms
 *  MEMORY: 9.8 MB
 *  DATE: 2-18-2023, 10:23:16 AM
 *
 */

// Solution:

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            auto temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        return root;
    }
};
