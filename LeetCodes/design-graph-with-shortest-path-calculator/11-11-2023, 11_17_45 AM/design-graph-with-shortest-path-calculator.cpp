// Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-graph-with-shortest-path-calculator
 *  RUNTIME: 117 ms
 *  MEMORY: 76.2 MB
 *  DATE: 11-11-2023, 11:17:45 AM
 *
 */

// Solution:

class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {    
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return find(node1, node2);
    }

    int find(int source, int end) {
        int n = adj.size();
        vector<int> minDist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, source});
        minDist[source] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if(node == end)
                return dist;
            for(auto &x: adj[node]) {
                int next = x.first;
                int newDist = dist + x.second;
                if(newDist < minDist[next]) {
                    minDist[next] = newDist;
                    pq.push({newDist, next});
                }
            }
        }
        if(minDist[end] == INT_MAX)
            return -1;
        return minDist[end];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
