// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-duplicates-from-sorted-list
 *  RUNTIME: 7 ms
 *  MEMORY: 11.5 MB
 *  DATE: 8-2-2023, 10:14:45 AM
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL && ptr->next != NULL) {
            if(ptr->val == ptr->next->val) {
                ptr->next = ptr->next->next;
                continue;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
