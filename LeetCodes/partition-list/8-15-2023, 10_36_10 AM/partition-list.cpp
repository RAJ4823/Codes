// Link: https://leetcode.com/problems/partition-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: partition-list
 *  RUNTIME: 9 ms
 *  MEMORY: 10.5 MB
 *  DATE: 8-15-2023, 10:36:10 AM
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr;
        ListNode* ptr = head;
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* l = left;
        ListNode* r = right;
        
        while(ptr != NULL) {
            int val = ptr->val;
            if(val < x) {
                l->next = new ListNode(val);
                l = l->next;
            } else {
                r->next = new ListNode(val);
                r = r->next;
            }
            ptr = ptr->next;
        }
        l->next = right->next;
        return left->next;
    }
};
