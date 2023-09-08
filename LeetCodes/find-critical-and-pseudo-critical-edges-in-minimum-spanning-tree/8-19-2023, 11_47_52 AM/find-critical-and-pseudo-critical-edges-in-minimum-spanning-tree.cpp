// Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
 *  RUNTIME: 80 ms
 *  MEMORY: 19.3 MB
 *  DATE: 8-19-2023, 11:47:52 AM
 *
 */

// Solution:

class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        size.resize(n, 1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    bool merge(int x, int y) {
        // int px = par[x];
        // int py = par[y];
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return false;

        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }
        return true;
    }

    bool isMst() {
        int root = findPar(0);
        return size[root] == par.size();
    }
};

class Solution {
public:
    int getMstWeight(int n, int m, int ex, int in, vector<vector<int>> &edges) {
        DisjointSet ds(n);
        int weight = 0;

        if(in != -1) {
            ds.merge(edges[in][0], edges[in][1]);
            weight = edges[in][2];
        }

        for(int j=0; j<m; j++) {
            if(j == ex || j == in) continue;
            if(ds.merge(edges[j][0], edges[j][1])) {
                weight += edges[j][2];
            }
        }

        if(!ds.isMst()) return 1e9;
        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i=0; i<m; i++) edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> critical, psudo;
        int mstWeight = getMstWeight(n, m, -1, -1, edges);

        for(int i=0; i<m; i++) {
            int weightWithout = getMstWeight(n, m, i, -1, edges);

            if(weightWithout > mstWeight) {
                critical.push_back(edges[i][3]);
            } else {
                int weightWith = getMstWeight(n, m, -1, i, edges);
                if(weightWith == mstWeight) {
                    psudo.push_back(edges[i][3]);
                }
            }
        }

        return {critical, psudo};
    }
};

// vector<int> critical, pseudoCritical;
// for (int i = 0; i < m; ++i) {
//     DSU tempDsu(n);
//     int weightWithout = 0;
//     for (int j = 0; j < m; ++j) {
//         if (i != j && tempDsu.unite(edges[j][0], edges[j][1]))
//             weightWithout += edges[j][2];
//     }
    
//     if (tempDsu.getSize(0) != n || weightWithout > mstWeight)
//         critical.push_back(edges[i][3]); // Store the original index
//     else {
//         DSU newDsu(n);
//         newDsu.unite(edges[i][0], edges[i][1]);
//         int weightWith = edges[i][2];
//         for (int j = 0; j < m; ++j) {
//             if (i != j && newDsu.unite(edges[j][0], edges[j][1]))
//                 weightWith += edges[j][2];
//         }
        
//         if (weightWith == mstWeight)
//             pseudoCritical.push_back(edges[i][3]); // Store the original index
//     }
// }
