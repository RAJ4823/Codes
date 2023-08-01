// Link: https://leetcode.com/problems/linked-list-random-node

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: linked-list-random-node
 *  RUNTIME: 26 ms
 *  MEMORY: 16.9 MB
 *  DATE: 3-10-2023, 12:06:24 PM
 *
 */

// Solution:

class Solution {
public:
    vector<ListNode*> nodes;
    Solution(ListNode* head) {
        while(head != NULL) {
            nodes.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return nodes[rand() % nodes.size()]->val;
    }
};
