// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: checking-existence-of-edge-length-limited-paths
 *  RUNTIME: 657 ms
 *  MEMORY: 110 MB
 *  DATE: 4-29-2023, 10:07:36 AM
 *
 */

// Solution:

// TC: O(NlogN) + O(ElogE)
// SC: O(N)

class DSU {
private:
    vector<int> par, size;
public:
    DSU(int n) {
        par.resize(n, -1);
        size.resize(n, 1);
    }

    int findPar(int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par[x]);
    }

    void merge(int a, int b) {
        int par_a = findPar(a);
        int par_b = findPar(b);

        if(par_a == par_b) 
            return;
        if(size[par_a] <= size[par_b]) {
            par[par_a] = par_b;
            size[par_b] += size[par_a];
        } else {
            par[par_b] = par_a;
            size[par_a] += size[par_b];
        }
    }

    bool areSame(int a, int b) {
        int par_a = findPar(a);
        int par_b = findPar(b);
        return (par_a == par_b);
    }
};

class Solution {
public:
    static bool sortByLimit(const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges,  vector<vector<int>>& queries) {
        int m = queries.size();
        int e = edges.size();
        for(int i=0; i<m; i++) {
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), sortByLimit);
        sort(edges.begin(), edges.end(), sortByLimit);

        DSU ds(n);
        vector<bool> ans(m);

        int j = 0;
        for(auto &query: queries) {
            int a = query[0];
            int b = query[1];
            int limit = query[2];
            int index = query[3];

            while(j < e && edges[j][2] < limit) {
                ds.merge(edges[j][0], edges[j][1]);
                j++;
            }
            ans[index] = ds.areSame(a, b);
        }
        return ans;
    }
};
