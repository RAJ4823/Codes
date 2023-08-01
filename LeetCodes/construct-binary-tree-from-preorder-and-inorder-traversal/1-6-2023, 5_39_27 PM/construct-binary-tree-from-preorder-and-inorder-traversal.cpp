// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: construct-binary-tree-from-preorder-and-inorder-traversal
 *  RUNTIME: 55 ms
 *  MEMORY: 26 MB
 *  DATE: 1-6-2023, 5:39:27 PM
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
private:
    int index = 0;
    TreeNode* build(vector<int>& pre, vector<int>& in, int start, int end) {
        if(start > end) return NULL;
        
        int value = pre[index++];
        TreeNode* node = new TreeNode(value);

        if(start == end) return node;

        int pivot = findIndex(in, value, start, end);
        if(pivot == -1) return node;
        
        node->left = build(pre, in, start, pivot-1);
        node->right = build(pre, in, pivot+1, end);
        return node;
    }

    int findIndex(vector<int> &arr, int key, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(arr[i] == key)
                return i;
        }
        return -1;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre, in, 0, n - 1);
    }
};
