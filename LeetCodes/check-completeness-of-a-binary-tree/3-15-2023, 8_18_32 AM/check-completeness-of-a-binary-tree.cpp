// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-completeness-of-a-binary-tree
 *  RUNTIME: 7 ms
 *  MEMORY: 10.4 MB
 *  DATE: 3-15-2023, 8:18:32 AM
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
    bool isCompleteTree(TreeNode* root) {
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node == NULL){
                flag = false;
            }
            else{
                if(flag == false)
                    return false;
                
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        return true;
    }
};
