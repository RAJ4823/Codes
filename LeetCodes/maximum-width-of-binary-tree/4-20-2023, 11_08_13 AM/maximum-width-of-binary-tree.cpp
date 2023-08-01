// Link: https://leetcode.com/problems/maximum-width-of-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-width-of-binary-tree
 *  RUNTIME: 8 ms
 *  MEMORY: 17.4 MB
 *  DATE: 4-20-2023, 11:08:13 AM
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

#define ll size_t

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        ll maxWidth = 0;
        while(!q.empty()) {
            maxWidth = max(maxWidth, q.back().second - q.front().second + 1);

            int size = q.size();
            for(int i=0; i<size; i++) {
                auto node = q.front().first;
                ll index = q.front().second;
                q.pop();

                if(node->left) q.push({node->left, index*2});
                if(node->right) q.push({node->right, index*2 + 1});    
            }      
        }
        return maxWidth;
    }
};
