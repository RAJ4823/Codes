// Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-depth-of-n-ary-tree
 *  RUNTIME: 17 ms
 *  MEMORY: 10.8 MB
 *  DATE: 2-19-2023, 9:44:43 AM
 *
 */

// Solution:

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* root) {
        if(root==NULL) return 0;
        int maxDepth = 1;
        for(auto &child: root->children) {
            maxDepth = max(maxDepth, 1 + dfs(child));
        }
        return maxDepth;
    }
    int maxDepth(Node* root) {
        return dfs(root);
    }
};
