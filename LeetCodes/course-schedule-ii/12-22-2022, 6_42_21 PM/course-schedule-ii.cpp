// Link: https://leetcode.com/problems/course-schedule-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: course-schedule-ii
 *  RUNTIME: 17 ms
 *  MEMORY: 12.9 MB
 *  DATE: 12-22-2022, 6:42:21 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &x : edges)
            adj[x[1]].push_back(x[0]);

        //! Kahn's Algorithm for finding topological sort: start
        vector<int> ind(V, 0);
        for (int i = 0; i < V; i++)
            for (auto &x : adj[i])
                ind[x]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (ind[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto &x : adj[node])
            {
                ind[x]--;
                if (ind[x] == 0)
                    q.push(x);
            }
        }
        //! Algo end

        if (topo.size() == V)
            return topo;
        return {};
    }
};
