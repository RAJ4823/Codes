// Link: https://leetcode.com/problems/min-cost-to-connect-all-points

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: min-cost-to-connect-all-points
 *  RUNTIME: 382 ms
 *  MEMORY: 58.8 MB
 *  DATE: 9-15-2023, 9:43:43 AM
 *
 */

// Solution:

class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) 
            par[i] = i;
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    bool merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) 
           return false;

        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }

        return true;
    }
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
		vector<pair<int, pair<int,int>>> edges;
        DisjointSet ds(n);

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int m = edges.size(), cost = 0;

        for(auto &edge: edges) {
            int w = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;

            if(ds.merge(x, y)) {
                cost += w;
            }
        }
        return cost;
    }
};
