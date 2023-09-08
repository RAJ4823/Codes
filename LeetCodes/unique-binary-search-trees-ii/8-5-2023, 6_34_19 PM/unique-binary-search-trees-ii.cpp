// Link: https://leetcode.com/problems/unique-binary-search-trees-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-binary-search-trees-ii
 *  RUNTIME: 11 ms
 *  MEMORY: 12.3 MB
 *  DATE: 8-5-2023, 6:34:19 PM
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
        map<pair<int, int>, vector<TreeNode*>> dp; 
            
                vector<TreeNode*> generateTrees(int n) {
                        return helper(1, n);
                            }
                                
                                    vector<TreeNode*> helper(int start, int end) {
                                            vector<TreeNode*> variations;
                                                    if (start > end) {
                                                                variations.push_back(nullptr);
                                                                            return variations;
                                                                                    }
                                                                                            if (dp.find(make_pair(start, end)) != dp.end()) {
                                                                                                        return dp[make_pair(start, end)];
                                                                                                                }
                                                                                                                        for (int i = start; i <= end; ++i) {
                                                                                                                                    vector<TreeNode*> leftSubTrees = helper(start, i - 1);
                                                                                                                                                vector<TreeNode*> rightSubTrees = helper(i + 1, end);
                                                                                                                                                            for (TreeNode* left : leftSubTrees) {
                                                                                                                                                                            for (TreeNode* right : rightSubTrees) {
                                                                                                                                                                                                TreeNode* root = new TreeNode(i);
                                                                                                                                                                                                                    root->left = left;
                                                                                                                                                                                                                                        root->right = right;
                                                                                                                                                                                                                                                            variations.push_back(root);
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                        dp[make_pair(start, end)] = variations;
                                                                                                                                                                                                                                                                                                                return variations;
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                    };

