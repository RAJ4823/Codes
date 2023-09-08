// Link: https://leetcode.com/problems/linked-list-cycle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: linked-list-cycle
 *  RUNTIME: 11 ms
 *  MEMORY: 8.1 MB
 *  DATE: 9-4-2023, 9:09:17 AM
 *
 */

// Solution:

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
