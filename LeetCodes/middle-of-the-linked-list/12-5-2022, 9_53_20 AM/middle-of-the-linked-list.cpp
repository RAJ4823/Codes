// Link: https://leetcode.com/problems/middle-of-the-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: middle-of-the-linked-list
 *  RUNTIME: 2 ms
 *  MEMORY: 6.9 MB
 *  DATE: 12-5-2022, 9:53:20 AM
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
    ListNode* middleNode(ListNode* head) {
        int i = 1;
        struct ListNode *ptr; 
        struct ListNode *temp;  
        // ptr = (struct ListNode *)malloc(sizeof(struct ListNode *)); 
        ptr = head;

        while(ptr->next != NULL)
        {
            i++;
            ptr = ptr->next;
        }
        i/=2;
        while(i--)
        {
            ptr = head;
            head = head->next;
        }
        return head;
    }
};
