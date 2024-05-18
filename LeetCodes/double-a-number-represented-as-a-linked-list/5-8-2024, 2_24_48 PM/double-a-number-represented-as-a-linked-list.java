// Link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: double-a-number-represented-as-a-linked-list
 *  RUNTIME: 5 ms
 *  MEMORY: 46.8 MB
 *  DATE: 5-8-2024, 2:24:48 PM
 *
 */

// Solution:

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    int carry;
    public void doubleValue(ListNode head) {
        if(head == null) return;

        doubleValue(head.next);

        int res = 2 * head.val + carry;
        carry = res / 10;

        head.val = res % 10;
    }

    public ListNode doubleIt(ListNode head) {
        carry = 0;
        doubleValue(head);

        return (carry == 0) ? head : new ListNode(carry, head);
    }
}
