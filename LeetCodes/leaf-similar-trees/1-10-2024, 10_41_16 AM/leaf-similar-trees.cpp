// Link: https://leetcode.com/problems/leaf-similar-trees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: leaf-similar-trees
 *  RUNTIME: 7 ms
 *  MEMORY: 13.1 MB
 *  DATE: 1-10-2024, 10:41:16 AM
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
    void fill_leafs(TreeNode* node, vector<int> &leafs) {
        if(!node) return;
        fill_leafs(node->left, leafs);
        if(!node->left && !node->right) {
            leafs.push_back(node->val);
        }
        fill_leafs(node->right, leafs);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        fill_leafs(root1, leafs1);
        fill_leafs(root2, leafs2);
        return leafs1 == leafs2;
    }
};
