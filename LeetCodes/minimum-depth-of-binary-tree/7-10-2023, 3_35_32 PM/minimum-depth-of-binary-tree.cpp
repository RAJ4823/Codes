// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-depth-of-binary-tree
 *  RUNTIME: 263 ms
 *  MEMORY: 144.5 MB
 *  DATE: 7-10-2023, 3:35:32 PM
 *
 */

// Solution:

class Solution {

public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto node = q.front();
                q.pop();

                if(node->left == NULL && node->right == NULL)
                    return level;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return level;
    }
};
