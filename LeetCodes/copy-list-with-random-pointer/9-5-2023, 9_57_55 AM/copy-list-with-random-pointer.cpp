// Link: https://leetcode.com/problems/copy-list-with-random-pointer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: copy-list-with-random-pointer
 *  RUNTIME: 7 ms
 *  MEMORY: 11.3 MB
 *  DATE: 9-5-2023, 9:57:55 AM
 *
 */

// Solution:

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        
        return mp[head];
    }
};
