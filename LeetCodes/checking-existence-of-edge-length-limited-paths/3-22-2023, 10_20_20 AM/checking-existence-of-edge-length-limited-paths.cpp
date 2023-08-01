// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: checking-existence-of-edge-length-limited-paths
 *  RUNTIME: 701 ms
 *  MEMORY: 110.1 MB
 *  DATE: 3-22-2023, 10:20:20 AM
 *
 */

// Solution:

// TC: O(NlogN) + O(ElogE)
// SC: O(N)

class DisjointSet {
    vector<int> par, size;
public:
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; ++i)
            par[i] = i;
    }

    int findPar(int node) {
        if (node == par[node])  return node;
        return par[node] = findPar(par[node]);
    }

    void unionBySize(int u, int v)
    {
        int x = findPar(u); 
        int y = findPar(v);

        if (x == y) return;
        if (size[x] < size[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
        }
    }

    bool isSamePar(int u, int v) {
        return findPar(u) == findPar(v);
    }
};

class Solution {
public:
    bool static comp(const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    }
   
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges,  vector<vector<int>>& queries) {
        int m = edges.size();
        int q = queries.size();

        for(int i=0; i<q; i++) {
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), comp);
        sort(edges.begin(), edges.end(), comp);

        int index = 0;
        DisjointSet ds(n);
        vector<bool> ans(q);

        for(auto &query: queries) {
            int limit = query[2];
            int queryIndex = query[3];

            while(index < m && edges[index][2] < limit) {
                ds.unionBySize(edges[index][0], edges[index][1]);
                index++;
            }
            ans[queryIndex] = ds.isSamePar(query[0], query[1]);
        }
        return ans;
    }
};
