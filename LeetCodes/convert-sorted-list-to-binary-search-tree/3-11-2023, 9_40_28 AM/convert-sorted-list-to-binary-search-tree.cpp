// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: convert-sorted-list-to-binary-search-tree
 *  RUNTIME: 32 ms
 *  MEMORY: 28.4 MB
 *  DATE: 3-11-2023, 9:40:28 AM
 *
 */

// Solution:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> vals;

    TreeNode* buildTree(int L, int R) {
        if(L > R) return NULL;
        int mid = (L+R)/2;
        return new TreeNode(vals[mid], buildTree(L, mid-1), buildTree(mid+1, R));
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while(head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }
        return buildTree(0, vals.size()-1);
    }
};
