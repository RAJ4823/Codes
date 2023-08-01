// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-max-number-of-edges-to-keep-graph-fully-traversable
 *  RUNTIME: 675 ms
 *  MEMORY: 138.8 MB
 *  DATE: 4-30-2023, 9:13:41 AM
 *
 */

// Solution:

class DSU {
private:
    vector<int> par, size;
public:
    DSU (int n){
        par.resize(n, -1);
        size.resize(n, 0);
    }

    int findPar(int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par[x]);
    }

    int mergeCost(int a, int b) {
        int pa = findPar(a);
        int pb = findPar(b);

        if(pa == pb) return 0;
        if(size[pa] <= size[pb]) {
            par[pa] = pb;
            size[pb] += size[pa];
        } else {
            par[pb] = pa;
            size[pa] += size[pb];
        }
        return 1;
    }

    bool areSame(int a, int b) {
        return findPar(a) == findPar(b);
    }

    bool isConnected() {
        int roots = 0;
        for(int i=0; i<par.size(); i++) {
            if(par[i] == -1) {
                roots++;
            } 
        }
        return (roots == 1);
    }
};

class Solution {
public:
    static bool sortByType(const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), sortByType);
        int totalEdges = edges.size();
        int requiredEdges = 0;

        DSU alice(n);
        DSU bob(n);

        for(auto &edge: edges) {
            int type = edge[0];
            int u = edge[1] - 1;
            int v = edge[2] - 1;
            
            if(type == 3) {
                requiredEdges += min(1, alice.mergeCost(u, v) + bob.mergeCost(u, v));
            } else if(type == 2) {
                requiredEdges += bob.mergeCost(u, v);
            } else {
                requiredEdges += alice.mergeCost(u, v); 
            }
        }

        if(alice.isConnected() && bob.isConnected()) {
            return totalEdges - requiredEdges;
        }
        return -1;
    }
};
