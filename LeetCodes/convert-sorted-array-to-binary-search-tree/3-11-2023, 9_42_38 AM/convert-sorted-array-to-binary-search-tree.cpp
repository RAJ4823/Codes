// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: convert-sorted-array-to-binary-search-tree
 *  RUNTIME: 17 ms
 *  MEMORY: 21.5 MB
 *  DATE: 3-11-2023, 9:42:38 AM
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
    TreeNode* buildTree(int L, int R, vector<int>& nums) {
        if(L > R) return NULL;
        int mid = (L+R)/2;
        return new TreeNode(nums[mid], buildTree(L, mid-1, nums), buildTree(mid+1, R, nums));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(0, nums.size()-1, nums);
    }
};
