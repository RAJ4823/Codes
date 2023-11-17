// Link: https://leetcode.com/problems/binary-tree-paths

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-tree-paths
 *  RUNTIME: 8 ms
 *  MEMORY: 13.8 MB
 *  DATE: 10-24-2023, 4:08:02 PM
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
    vector<string> paths;
    void find(TreeNode* node, string path) {
        if(!node) return;

        path += (path == "") ? to_string(node->val) : "->" + to_string(node->val);

        if(!node->left && !node->right)
            paths.push_back(path);

        if(node->left) 
            find(node->left, path);
        
        if(node->right) 
            find(node->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        
        find(root, "");
        return paths;
    }
};
