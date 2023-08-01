// Link: https://leetcode.com/problems/add-two-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-two-numbers
 *  RUNTIME: 28 ms
 *  MEMORY: 71.5 MB
 *  DATE: 12-6-2022, 2:21:19 PM
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
    ListNode* addTwoNumbers(ListNode* ptr, ListNode* str) {
        ListNode *ans = new ListNode(0);
        ListNode *x = ans;
        int carry = 0, num1 = 0, num2 = 0, sum = 0;
        while(ptr != NULL || str != NULL || carry != 0)
        {
            num1 = (ptr != NULL) ? ptr->val : 0;
            num2 = (str != NULL) ? str->val : 0;

            sum = num1 + num2 + carry;
            carry = (sum > 9) ? 1 : 0;
            x->next = new ListNode(sum%10);
            x = x->next;

            ptr = (ptr != NULL) ? ptr->next : ptr;
            str = (str != NULL) ? str->next : str;
        }
        return ans->next;
    }
};
