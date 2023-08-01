// Link: https://leetcode.com/problems/find-duplicate-subtrees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-duplicate-subtrees
 *  RUNTIME: 15 ms
 *  MEMORY: 33 MB
 *  DATE: 2-28-2023, 2:42:25 PM
 *
 */

// Solution:

class Solution {
public:
    unordered_map<string, vector<TreeNode*>> mp;
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "(" + serialize(root->left) + to_string(root->val) + serialize(root->right) + ")";
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicateSubtrees;
        serialize(root);
        for(auto &[str, vec]: mp) {
            if(vec.size() > 1) duplicateSubtrees.push_back(vec[0]);
        }
        return duplicateSubtrees; 
    }   
};
