// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: delete-the-middle-node-of-a-linked-list
 *  RUNTIME: 1081 ms
 *  MEMORY: 294.7 MB
 *  DATE: 5-15-2023, 9:55:44 AM
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

    ListNode* deleteMiddle(ListNode* head) {
        int len = getLen(head);
        int mid = len/2 - 1;
        if(mid < 0) return head->next;
        ListNode* ptr = head;
        while(mid--) {
            ptr = ptr->next;
        }
        // cout << ptr->val << endl;
        ptr->next = ptr->next->next;
        return head;
    }
};
