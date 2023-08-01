// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: swapping-nodes-in-a-linked-list
 *  RUNTIME: 726 ms
 *  MEMORY: 180.1 MB
 *  DATE: 5-15-2023, 9:34:37 AM
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

    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLen(head);
        ListNode* ptr = head;
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;

        int i = 0;
        while(ptr != NULL) {
            if(i == k - 1) {
                node1 = ptr;
            }
            if(len - i == k) {
                node2 = ptr;
            }
            ptr = ptr->next;
            i++;
        }

        swap(node1->val, node2->val);
        return head;
    }
};
