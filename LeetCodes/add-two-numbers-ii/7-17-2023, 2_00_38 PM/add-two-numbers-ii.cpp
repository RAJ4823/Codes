// Link: https://leetcode.com/problems/add-two-numbers-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-two-numbers-ii
 *  RUNTIME: 28 ms
 *  MEMORY: 73.7 MB
 *  DATE: 7-17-2023, 2:00:38 PM
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
    int getTop(stack<int> &s) {
        if(s.empty()) return 0;
        return s.top();
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* ans = NULL;
        int carry = 0;

        while(!s1.empty() || !s2.empty() || carry != 0) {
            int d1 = getTop(s1);
            int d2 = getTop(s2);

            int sum = d1 + d2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* node = new ListNode(digit);
            node->next = ans;
            ans = node;

            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }

        return ans;
    }
};
