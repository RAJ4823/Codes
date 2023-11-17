// Link: https://leetcode.com/problems/validate-binary-tree-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: validate-binary-tree-nodes
 *  RUNTIME: 39 ms
 *  MEMORY: 36.8 MB
 *  DATE: 10-17-2023, 5:42:40 PM
 *
 */

// Solution:

class Solution {

public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> parents(n, -1);

        

        // Step 1: Check if each child has a unique parent

        for(int i = 0; i < n; i++){

            if(leftChild[i] != -1){

                if(parents[leftChild[i]] == -1)

                    parents[leftChild[i]] = i; // Assign parent

                else return false; // Duplicate parent, not a valid binary tree

            }

            if(rightChild[i] != -1){

                if(parents[rightChild[i]] == -1)

                    parents[rightChild[i]] = i; // Assign parent

                else return false; // Duplicate parent, not a valid binary tree

            }

        }

        // Step 2: Find the root node

        int root = -1;

        for(int i = 0;i < n; i++){

            if(parents[i] == -1){

                if(root == -1) root = i; // Assign root

                else return false; // Multiple roots, not a valid binary tree

            }

        }

        if(root == -1) return false; // No root found, not a valid binary tree

        // Step 3: Detect cycles 

        unordered_set<int> visited;

        queue<int> toVisit;

        toVisit.push(root);

        while(!toVisit.empty()){

            int node = toVisit.front();

            toVisit.pop();

            if(visited.find(node) != visited.end()) 

                return false; // Cycle detected, not a valid binary tree

            visited.insert(node);

            if(rightChild[node] != -1) toVisit.push(rightChild[node]);

            if(leftChild[node] != -1) toVisit.push(leftChild[node]);

        }

        // Step 4: Detect disconnected nodes

        return visited.size() == n;

    }

};
