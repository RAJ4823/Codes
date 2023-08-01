// Link: https://leetcode.com/problems/swap-nodes-in-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: swap-nodes-in-pairs
 *  RUNTIME: 6 ms
 *  MEMORY: 7.5 MB
 *  DATE: 5-16-2023, 8:55:09 AM
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL) {
            if(ptr->next == NULL) break;

            swap(ptr->val, ptr->next->val);
            ptr = ptr->next->next;
        }
        return head;
    }
};
