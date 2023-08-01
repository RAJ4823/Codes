// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: construct-binary-tree-from-inorder-and-postorder-traversal
 *  RUNTIME: 33 ms
 *  MEMORY: 26 MB
 *  DATE: 3-16-2023, 8:26:36 AM
 *
 */

// Solution:

class Solution {
    int index = -1;
    TreeNode* build(vector<int>& post, vector<int>& in, int start, int end) {
        if(start > end) return NULL;
        if(index == -1) index = in.size() - 1;

        int value = post[index--];
        TreeNode* node = new TreeNode(value);

        if(start == end) return node;

        int pivot = findIndex(in, value, start, end);
        if(pivot == -1) return node;
        
        node->right = build(post, in, pivot+1, end);
        node->left = build(post, in, start, pivot-1);
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        return build(postorder, inorder, 0, n-1);
    }
};
