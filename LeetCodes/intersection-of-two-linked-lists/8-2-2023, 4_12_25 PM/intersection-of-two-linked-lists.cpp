// Link: https://leetcode.com/problems/intersection-of-two-linked-lists

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: intersection-of-two-linked-lists
 *  RUNTIME: 32 ms
 *  MEMORY: 14.6 MB
 *  DATE: 8-2-2023, 4:12:25 PM
 *
 */

// Solution:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        int len = 0;
        ListNode* list = head;
        while(list != NULL) {
            list = list->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);

        if(lenA > lenB) {
            while(lenA > lenB) {
                headA = headA->next;
                lenA--;
            }
        } else if(lenA < lenB){
            while(lenA < lenB) {
                headB = headB->next;
                lenB--;
            }
        }

        while(headA && headB) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
