// Link: https://leetcode.com/problems/delete-node-in-a-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: delete-node-in-a-linked-list
 *  RUNTIME: 0 ms
 *  MEMORY: 43.4 MB
 *  DATE: 5-8-2024, 5:07:30 PM
 *
 */

// Solution:

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
