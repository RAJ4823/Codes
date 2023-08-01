// Link: https://leetcode.com/problems/merge-k-sorted-lists

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-k-sorted-lists
 *  RUNTIME: 27 ms
 *  MEMORY: 14.1 MB
 *  DATE: 3-12-2023, 9:44:17 AM
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* sorted = new ListNode();
        map<int, int> m;
        for(int i=0; i<n; i++) {
            ListNode* ptr = lists[i];
            while(ptr != NULL) {
                m[ptr->val]++;
                ptr = ptr->next;
            }
        }
        ListNode* head = sorted;
        for(auto [val, count]: m) {
            while(count--) {
                sorted->next = new ListNode(val);
                sorted = sorted->next;
            }
        }
        return head->next;
    }
};
