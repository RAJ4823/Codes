// Link: https://leetcode.com/problems/satisfiability-of-equality-equations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: satisfiability-of-equality-equations
 *  RUNTIME: 8 ms
 *  MEMORY: 11.2 MB
 *  DATE: 8-26-2023, 10:42:39 AM
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
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return true;

        if(size[px] < size[py]) {
            par[py] = px;
            size[px] += size[py];
        } else {
            par[px] = py;
            size[py] += size[px];
        }
        return false;
    }

    bool hasSamePar(int x, int y) {
        return findPar(x) == findPar(y);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& eqs) {
        DisjointSet ds(26);
        for(auto &eq: eqs) {
            if(eq[1] == '=') {
                ds.merge(eq[0] - 'a', eq[3] - 'a');
            } 
        }
        for(auto &eq: eqs) {
            if(eq[1] == '!' && ds.hasSamePar(eq[0] - 'a', eq[3] - 'a')) {
                return false;
            } 
        }
        return true;
    }
};
