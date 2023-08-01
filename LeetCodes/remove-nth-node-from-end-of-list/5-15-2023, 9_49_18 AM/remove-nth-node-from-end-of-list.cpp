// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-nth-node-from-end-of-list
 *  RUNTIME: 3 ms
 *  MEMORY: 10.6 MB
 *  DATE: 5-15-2023, 9:49:18 AM
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
    int getLen(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;
        while(ptr != NULL) {
            ptr = ptr->next;
            len++;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        if(len == 1) return NULL;
        if(len == n) return head->next;

        ListNode* ptr = head;
        for(int i=0; i < len-n-1; i++) ptr = ptr->next;
        ptr->next = ptr->next->next;
        
        return head;
    }
};
