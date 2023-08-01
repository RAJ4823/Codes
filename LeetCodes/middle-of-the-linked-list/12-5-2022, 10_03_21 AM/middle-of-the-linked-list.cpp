// Link: https://leetcode.com/problems/middle-of-the-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: middle-of-the-linked-list
 *  RUNTIME: 0 ms
 *  MEMORY: 7.1 MB
 *  DATE: 12-5-2022, 10:03:21 AM
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
        ListNode *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = (ptr->next->next != NULL) ? ptr->next->next : ptr->next;
            head = head->next;
        }
        return head;
    }
};
