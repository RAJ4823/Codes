// Link: https://leetcode.com/problems/odd-even-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: odd-even-linked-list
 *  RUNTIME: 22 ms
 *  MEMORY: 10.5 MB
 *  DATE: 12-6-2022, 10:39:14 AM
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
ListNode *head;
class Solution {
public:

    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return head;
        }
     
        ListNode *odd = head;
        ListNode *ptr = head->next;
        ListNode *even = ptr;

        while(ptr!=NULL && ptr->next!=NULL)
        {
            odd->next = ptr->next;
            odd = ptr->next;
            ptr->next = odd->next;
            ptr = odd->next;
        }
        odd->next=even;
        return head;
        
    }
};
