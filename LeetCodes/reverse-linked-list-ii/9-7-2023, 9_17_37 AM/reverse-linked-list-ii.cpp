// Link: https://leetcode.com/problems/reverse-linked-list-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-linked-list-ii
 *  RUNTIME: 0 ms
 *  MEMORY: 7.4 MB
 *  DATE: 9-7-2023, 9:17:37 AM
 *
 */

// Solution:

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* ptr = head;
        while(ptr) {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(arr.begin()  + left - 1, arr.begin() + right);
        ptr = head;
        int i = 0;
        while(ptr) {
            ptr->val = arr[i++];
            ptr = ptr->next;
        }
        return head;
    }
};
