// Link: https://leetcode.com/problems/linked-list-random-node

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: linked-list-random-node
 *  RUNTIME: 20 ms
 *  MEMORY: 16.8 MB
 *  DATE: 3-10-2023, 12:04:15 PM
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
    vector<ListNode*> nodes;
    Solution(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL) {
            nodes.push_back(ptr);
            ptr=ptr->next;
        }
    }
    
    int getRandom() {
        int size = nodes.size();
        int index = rand() % size;
        return nodes[index]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
