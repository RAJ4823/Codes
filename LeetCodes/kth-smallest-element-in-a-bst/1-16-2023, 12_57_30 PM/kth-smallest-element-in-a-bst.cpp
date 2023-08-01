// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-smallest-element-in-a-bst
 *  RUNTIME: 18 ms
 *  MEMORY: 24.2 MB
 *  DATE: 1-16-2023, 12:57:30 PM
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
    int count = 0, ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        if(ans == -1) {
            kthSmallest(root->left, k);
            if(++count == k) ans = root->val;
            kthSmallest(root->right, k);
        }
        return ans;
    }
};
