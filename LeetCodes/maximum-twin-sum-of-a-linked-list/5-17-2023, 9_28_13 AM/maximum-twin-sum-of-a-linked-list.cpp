// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-twin-sum-of-a-linked-list
 *  RUNTIME: 270 ms
 *  MEMORY: 118.8 MB
 *  DATE: 5-17-2023, 9:28:13 AM
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
    int getLen(ListNode *head) {
        ListNode* ptr = head;
        int len = 0;
        while(ptr != NULL) {
            ptr = ptr->next;
            len++;
        }
        return len;
    }
    int pairSum(ListNode* head) {
        int n = getLen(head), i =0;
        vector<int> sum(n/2, 0);
        
        ListNode* ptr = head;
        while(ptr != NULL) {
            int index = min(i, n - 1 - i);
            sum[index] += ptr->val;
            ptr = ptr->next;
            i++;
        }
        int ans = 0;
        for(auto &val: sum) {
            ans = max(ans, val);
        }
        return ans;
    }
};
