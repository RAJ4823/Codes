// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-zero-sum-consecutive-nodes-from-linked-list
 *  RUNTIME: 2 ms
 *  MEMORY: 43.8 MB
 *  DATE: 3-14-2024, 12:51:22 PM
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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode list = new ListNode(0, head);
        Map<Integer, ListNode> mp = new HashMap<>();

        ListNode ptr = list;
        int sum = 0;


        while(ptr != null) {
            sum += ptr.val;
            mp.put(sum, ptr);
            ptr = ptr.next;
        }

        sum = 0;
        ptr = list;

        while(ptr != null) {
            sum += ptr.val;
            ptr.next = mp.get(sum).next;
            ptr = ptr.next;
        }
        return list.next;
    } 
}
