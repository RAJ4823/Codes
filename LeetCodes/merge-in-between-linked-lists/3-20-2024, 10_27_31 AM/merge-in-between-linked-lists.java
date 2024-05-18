// Link: https://leetcode.com/problems/merge-in-between-linked-lists

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-in-between-linked-lists
 *  RUNTIME: 1 ms
 *  MEMORY: 46.7 MB
 *  DATE: 3-20-2024, 10:27:31 AM
 *
 */

// Solution:

class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode currNode = list1;
        int index = 0;
        while (index < a - 1) {
            currNode = currNode.next;
            index++;
        }
        ListNode front = currNode;
        while (index < b + 1) {
            currNode = currNode.next;
            index++;
        }
        ListNode rear = currNode;
        ListNode secondListTail = list2, secondListHead = list2;
        while (secondListTail.next != null) {
            secondListTail = secondListTail.next;
        }
        front.next = secondListHead;
        secondListTail.next = rear;
        return list1;
    }
}
