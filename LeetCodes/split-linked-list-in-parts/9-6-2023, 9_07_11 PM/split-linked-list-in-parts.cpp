// Link: https://leetcode.com/problems/split-linked-list-in-parts

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: split-linked-list-in-parts
 *  RUNTIME: 3 ms
 *  MEMORY: 8.8 MB
 *  DATE: 9-6-2023, 9:07:11 PM
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
 * }
public:
int k) {
    **/    

class Solution {
    public:
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
                int length = 0;
                        ListNode* current = head;
                                vector<ListNode*> parts;

                                        while (current) {
                                                    length++;
                                                                current = current->next;
                                                                        }

                                                                                int base_size = length / k, extra = length % k;
                                                                                        current = head;

                                                                                                for (int i = 0; i < k; ++i) {
                                                                                                            int part_size = base_size + (extra > 0);
                                                                                                                        ListNode* part_head = nullptr, * part_tail = nullptr;

                                                                                                                                    for (int j = 0; j < part_size; ++j) {
                                                                                                                                                    if (!part_head) {
                                                                                                                                                                        part_head = part_tail = current;
                                                                                                                                                                                        } else {
                                                                                                                                                                                                            part_tail->next = current;
                                                                                                                                                                                                                                part_tail = part_tail->next;
                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                if (current) {
                                                                                                                                                                                                                                                                                    current = current->next;
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                            if (part_tail) {
                                                                                                                                                                                                                                                                                                                                            part_tail->next = nullptr;
                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                    parts.push_back(part_head);
                                                                                                                                                                                                                                                                                                                                                                                extra = max(extra - 1, 0);
                                                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                                                return parts;
                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                    };

