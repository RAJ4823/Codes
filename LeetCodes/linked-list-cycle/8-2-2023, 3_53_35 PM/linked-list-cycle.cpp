// Link: https://leetcode.com/problems/linked-list-cycle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: linked-list-cycle
 *  RUNTIME: 7 ms
 *  MEMORY: 8 MB
 *  DATE: 8-2-2023, 3:53:35 PM
 *
 */

// Solution:

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
