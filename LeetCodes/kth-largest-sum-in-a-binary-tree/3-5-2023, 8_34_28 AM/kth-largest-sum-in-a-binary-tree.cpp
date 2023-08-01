// Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-largest-sum-in-a-binary-tree
 *  RUNTIME: 227 ms
 *  MEMORY: 98.2 MB
 *  DATE: 3-5-2023, 8:34:28 AM
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> sums;
        q.push(root);
        
        while(!q.empty()) {
            long long size = q.size();
            long long level_sum = 0;
            for(int i=0; i< size; i++) {
                auto node = q.front();
                q.pop();
                level_sum += (node->val);
                
                if(node->left != NULL) q.push(node->left);
                if(node->right!= NULL) q.push(node->right);
            }
            sums.push_back(level_sum);
        }
        
        sort(sums.begin(), sums.end(), greater<long long> ());
        if(k - 1 >= sums.size()) return -1;
        return sums[k - 1];
    }
};
