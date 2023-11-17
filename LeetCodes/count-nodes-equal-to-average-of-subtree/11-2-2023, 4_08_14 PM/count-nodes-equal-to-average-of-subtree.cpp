// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-nodes-equal-to-average-of-subtree
 *  RUNTIME: 11 ms
 *  MEMORY: 23.7 MB
 *  DATE: 11-2-2023, 4:08:14 PM
 *
 */

// Solution:

class Solution {
public:
    int ans = 0;
    vector<int> find(TreeNode* node) {
        if(!node) return {0, 0};

        vector<int> left = find(node->left);
        vector<int> right = find(node->right);

        int sum = node->val + left[0] + right[0];
        int count = 1 + left[1] + right[1];
        if(sum / count == node->val)
            ans++;
            
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        find(root);
        return ans;
    }
};
