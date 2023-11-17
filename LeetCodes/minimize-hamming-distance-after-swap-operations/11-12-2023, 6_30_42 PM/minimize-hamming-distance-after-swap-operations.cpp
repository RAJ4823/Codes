// Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimize-hamming-distance-after-swap-operations
 *  RUNTIME: 284 ms
 *  MEMORY: 143.2 MB
 *  DATE: 11-12-2023, 6:30:42 PM
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
        if(size[px] > size[py]) {
            par[py] = px;
            size[px] += size[py];
        } else {
            par[px] = py;
            size[py] += size[px];
        }
        return true;
    }

    bool isSamePar(int x, int y) {
        return findPar(x) == findPar(y);
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DisjointSet ds(n);
        for(auto &swaps: allowedSwaps) {
            ds.merge(swaps[0], swaps[1]);
        }

        vector<unordered_multiset<int>> subs(n);
        for(int i=0; i<n; i++) {
            subs[ds.findPar(i)].insert(source[i]);
        }

        int count = 0;
        for(int i=0; i<n; i++) {
            auto &st = subs[ds.par[i]];
            if(st.count(target[i])) 
                st.erase(st.find(target[i]));
            else
                count++;
        }
        return count;
    }
};
