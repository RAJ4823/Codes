// Link: https://leetcode.com/problems/palindrome-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: palindrome-linked-list
 *  RUNTIME: 346 ms
 *  MEMORY: 120.6 MB
 *  DATE: 1-26-2023, 10:49:36 AM
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
    bool isPalindrome(ListNode* head) {
        string s = "";
        while(head != NULL) {
            s += head->val;
            head = head->next;
        }
        int i = 0, j = s.length() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
};
