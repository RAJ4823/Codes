// Link: https://leetcode.com/problems/smallest-string-with-swaps

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-string-with-swaps
 *  RUNTIME: 94 ms
 *  MEMORY: 46.8 MB
 *  DATE: 11-13-2023, 9:58:13 AM
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

    void merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py)
            return;
        if(size[px] > size[py]) {
            par[py] = px;
            size[px] += size[py];
        } else {
            par[px] = py;
            size[py] += size[px];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet ds(n);

        for(auto &pair: pairs) {
            ds.merge(pair[0], pair[1]);
        }
        unordered_map<int, string> group;
        for(int i=0; i<n; i++) {
            int root = ds.findPar(i);
            group[root].push_back(s[i]);
        }

        if(group.size() == 1) {
            sort(s.begin(), s.end());
            return s;
        }

        for(auto &[root, str]: group) {
            sort(str.rbegin(), str.rend());
        }
        for(int i=0; i<n; i++) {
            int root = ds.findPar(i);
            s[i] = group[root].back();
            group[root].pop_back();
        }
        return s;
    }
};
