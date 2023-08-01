// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-root-to-leaf-numbers
 *  RUNTIME: 3 ms
 *  MEMORY: 9.3 MB
 *  DATE: 3-14-2023, 9:05:10 AM
 *
 */

// Solution:

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* node, int num) {
        if(node == NULL) return;
        
        num *= 10;
        num += node->val;
        if(node->left == NULL && node->right == NULL) 
            ans += num;
        
        dfs(node->left, num);
        dfs(node->right, num);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
