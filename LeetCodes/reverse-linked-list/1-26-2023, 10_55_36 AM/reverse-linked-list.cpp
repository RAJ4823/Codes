// Link: https://leetcode.com/problems/reverse-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-linked-list
 *  RUNTIME: 14 ms
 *  MEMORY: 8.2 MB
 *  DATE: 1-26-2023, 10:55:36 AM
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) 
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head -> next;
        
        while(next != NULL) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;
        return curr;    
    }
};
