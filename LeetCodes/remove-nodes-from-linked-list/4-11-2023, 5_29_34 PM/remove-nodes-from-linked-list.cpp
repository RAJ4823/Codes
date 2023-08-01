// Link: https://leetcode.com/problems/remove-nodes-from-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-nodes-from-linked-list
 *  RUNTIME: 466 ms
 *  MEMORY: 181.7 MB
 *  DATE: 4-11-2023, 5:29:34 PM
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
    ListNode* removeNodes(ListNode* head) {
        vector<int> nodes, v;
        ListNode* ptr = head;
        while(ptr != NULL) {
            nodes.push_back(ptr->val);
            ptr = ptr->next;
        }

        ListNode* ans = new ListNode(0);
        ptr = ans;
        int max = 0;
        for(int i=nodes.size()-1; i>=0;i--) {
            if(nodes[i] >= max) {
                v.push_back(nodes[i]);
                max = nodes[i];
            }
        }
        for(int i=v.size()-1; i>=0; i--) {
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
        return ans->next;
    }
};
