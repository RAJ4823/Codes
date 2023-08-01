// Link: https://leetcode.com/problems/course-schedule

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: course-schedule
 *  RUNTIME: 21 ms
 *  MEMORY: 13 MB
 *  DATE: 12-22-2022, 6:26:30 PM
 *
 */

// Solution:

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto &edge: edges) 
        {
            adj[edge[0]].push_back(edge[1]);
        }

        //! Kahn's Algorithms for Detecting Cycle in directed graph
        vector<int> ans, inDegree(V, 0);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
                inDegree[x]++;
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto neigh : adj[node])
            {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return (ans.size() == V);
    }
};
