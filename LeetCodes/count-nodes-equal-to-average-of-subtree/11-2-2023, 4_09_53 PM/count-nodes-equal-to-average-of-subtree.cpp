// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-nodes-equal-to-average-of-subtree
 *  RUNTIME: 6 ms
 *  MEMORY: 12.2 MB
 *  DATE: 11-2-2023, 4:09:53 PM
 *
 */

// Solution:

class Solution {
public:
    int ans = 0;
    pair<int,int> find(TreeNode* node) {
        if(!node) return {0, 0};

        auto left = find(node->left);
        auto right = find(node->right);

        int sum = node->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        if(sum / count == node->val)
            ans++;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        find(root);
        return ans;
    }
};
