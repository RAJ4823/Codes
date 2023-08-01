// Link: https://leetcode.com/problems/path-sum-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-sum-iii
 *  RUNTIME: 33 ms
 *  MEMORY: 16 MB
 *  DATE: 1-11-2023, 10:02:09 PM
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
    long long int dfs(TreeNode* root, long long int prevSum, long long int& target){
        if(root == NULL) return 0;
        long long int currSum = prevSum + root->val;
        long long int paths = dfs(root->left, currSum, target) + dfs(root->right, currSum, target);
        if(currSum == target)
            return 1 + paths;
        return paths;
    }

public:
    long long int pathSum(TreeNode* root, long long int sum) {
        if(root == NULL) return 0;
        long long int leftTreeSum =  pathSum(root->left, sum);
        long long int rightTreeSum = pathSum(root->right, sum);
        return dfs(root, 0, sum) + leftTreeSum + rightTreeSum;
    }
};
