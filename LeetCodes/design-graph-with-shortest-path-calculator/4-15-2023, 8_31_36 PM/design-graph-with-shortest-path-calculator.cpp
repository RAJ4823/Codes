// Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-graph-with-shortest-path-calculator
 *  RUNTIME: 344 ms
 *  MEMORY: 77.6 MB
 *  DATE: 4-15-2023, 8:31:36 PM
 *
 */

// Solution:

class Graph {
public:
    vector<vector<pair<int,int>>> g;
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto &e:edges) {
            g[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        g[e[0]].push_back({e[1], e[2]});
    }
    
    int find(int S, int E)
    {
        int V = g.size();
        // Priority queue is used to get minimum {dist, node} for each iteration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minDist(V, 1e9);
        

        pq.push({0, S});
        minDist[S] = 0;

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse each adjecent node of 'node'
            for (auto &edge : g[node])
            {
                int neigh = edge.first;
                int weight = edge.second;

                if (dist + weight < minDist[neigh])
                {
                    minDist[neigh] = dist + weight;
                    pq.push({minDist[neigh], neigh});
                }
            }
        }
        if(minDist[E] == 1e9)
            return -1;
        return minDist[E];
    }
    
    int shortestPath(int node1, int node2) {
        return find(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
