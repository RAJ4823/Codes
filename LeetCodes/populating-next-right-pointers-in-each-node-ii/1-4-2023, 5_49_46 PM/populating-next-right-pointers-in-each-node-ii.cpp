// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: populating-next-right-pointers-in-each-node-ii
 *  RUNTIME: 13 ms
 *  MEMORY: 17.6 MB
 *  DATE: 1-4-2023, 5:49:46 PM
 *
 */

// Solution:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root; 
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            Node* node = q.front(); 
            q.pop();

            if (node==NULL) 
            {
                if (q.size() > 0) 
                    q.push(NULL);
            }
            else
            {
                node->next = q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        return root;
    }
};
