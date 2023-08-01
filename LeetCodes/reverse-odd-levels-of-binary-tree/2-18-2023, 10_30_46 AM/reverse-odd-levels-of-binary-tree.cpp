// Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-odd-levels-of-binary-tree
 *  RUNTIME: 249 ms
 *  MEMORY: 77.1 MB
 *  DATE: 2-18-2023, 10:30:46 AM
 *
 */

// Solution:

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> vals;
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while(size--) {
                auto node = q.front();
                q.pop();
                if(level%2) {
                    node->val = vals[size];
                }
                if(node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            vals = temp;
            level++;
        }
        return root;
    }
};
