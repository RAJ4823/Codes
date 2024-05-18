// Link: https://leetcode.com/problems/remove-nodes-from-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-nodes-from-linked-list
 *  RUNTIME: 11 ms
 *  MEMORY: 75.1 MB
 *  DATE: 5-8-2024, 2:41:12 PM
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

    public ListNode removeNodes(ListNode head) {
        if(head == null) return null;

        ListNode node = head;
        ListNode maxNode = removeNodes(head.next);
        node.next = maxNode;
        if(maxNode == null || node.val >= maxNode.val)
            return node;
        return maxNode;
    }
}
