// Link: https://leetcode.com/problems/all-possible-full-binary-trees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: all-possible-full-binary-trees
 *  RUNTIME: 104 ms
 *  MEMORY: 28.1 MB
 *  DATE: 7-23-2023, 9:44:04 AM
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
    vector<vector<TreeNode*>> dp;

    vector<TreeNode*> generate(int n) {
        if(n % 2 == 0)  return {};
        if(dp[n].size() != 0) return dp[n];
        if(n == 1) return {new TreeNode(0)};

        vector<TreeNode*> tree;
        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> LST = generate(i); // left subtree
            vector<TreeNode*> RST = generate(n-i-1); // right subtree

            for(auto &l: LST) {
                for(auto &r: RST) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    tree.push_back(root);
                }
            }
        }
        return dp[n] = tree;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n+1);
        return generate(n);
    }
};
