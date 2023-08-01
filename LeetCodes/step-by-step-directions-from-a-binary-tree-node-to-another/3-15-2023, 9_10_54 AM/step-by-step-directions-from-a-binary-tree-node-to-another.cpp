// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: step-by-step-directions-from-a-binary-tree-node-to-another
 *  RUNTIME: 216 ms
 *  MEMORY: 115.3 MB
 *  DATE: 3-15-2023, 9:10:54 AM
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
    TreeNode* nearest_parent(TreeNode *root, int startValue, int destValue) {
        if(root == NULL) return NULL;
        if(root->val == startValue) return root;
        if(root->val == destValue) return root;
        TreeNode* left = nearest_parent(root->left, startValue, destValue);
        TreeNode* right = nearest_parent(root->right, startValue, destValue);
        if(left && right) return root;

        if(left) return left;
        return right;
    }

    bool getPath(TreeNode *root, int value, string &path) {
        if(root == NULL) return false;
        if(root->val == value) return true;

        path += 'L';
        if(getPath(root->left, value, path)) return true;
        path.pop_back();

        path += 'R';
        if(getPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* parent = nearest_parent(root, startValue, destValue);

        string startPath, destPath;
        getPath(parent, startValue, startPath);
        getPath(parent, destValue, destPath);
        for(auto &ch: startPath) ch = 'U';
        return startPath + destPath;
    }
};
