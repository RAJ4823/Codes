// Link: https://leetcode.com/problems/linked-list-cycle-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: linked-list-cycle-ii
 *  RUNTIME: 12 ms
 *  MEMORY: 10 MB
 *  DATE: 3-9-2023, 10:20:48 AM
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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> index;
        ListNode* ptr = head;
        int i = 0;
        while(ptr != NULL) {
            if(index.find(ptr) == index.end()) {
                index[ptr] = i++;
            } else{
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }
};
