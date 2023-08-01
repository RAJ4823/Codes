// Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-unreachable-pairs-of-nodes-in-an-undirected-graph
 *  RUNTIME: 553 ms
 *  MEMORY: 180.8 MB
 *  DATE: 3-25-2023, 10:18:57 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    ll dfs(int source, vector<bool> &vis, vector<int> graph[]) {
        int countNodes = 1;
        vis[source] = true;
        for(auto &next: graph[source]) {
            if(!vis[next]) {
                countNodes += dfs(next, vis, graph);
            }
        }
        return countNodes;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<ll> nodes;
        vector<int> graph[n];
        vector<bool> vis(n, false);

        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }


        ll totalNodes = 0, unreachablePairs = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ll currNodes = dfs(i, vis, graph);
                totalNodes += currNodes;
                nodes.push_back(currNodes);
            }
        }

        for(auto &count: nodes) {
            unreachablePairs += ((totalNodes - count) * count);
        }
        return unreachablePairs/2;
    }
};
