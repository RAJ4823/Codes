// Link: https://leetcode.com/problems/clone-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: clone-graph
 *  RUNTIME: 0 ms
 *  MEMORY: 9.2 MB
 *  DATE: 4-8-2023, 5:15:02 PM
 *
 */

// Solution:

class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;

        for(auto it:cur->neighbors)
        {
            if(mp.find(it)!=mp.end()) 
            {
                neighbour.push_back(mp[it]);
            }
            else
                neighbour.push_back(dfs(it,mp));
        }

        clone->neighbors=neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;

        if(node==NULL) return NULL;
        
        if(node->neighbors.size()==0)
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};
