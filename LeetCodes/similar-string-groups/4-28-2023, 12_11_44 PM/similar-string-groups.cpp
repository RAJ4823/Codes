// Link: https://leetcode.com/problems/similar-string-groups

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: similar-string-groups
 *  RUNTIME: 353 ms
 *  MEMORY: 10.1 MB
 *  DATE: 4-28-2023, 12:11:44 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> par;

    int findPar(int x) {
        if(par[x] < 0) return x;
        return par[x] = findPar(par[x]);
    }

    void merge(int a, int b) {
        int par_a = findPar(a);
        int par_b = findPar(b);

        if(par_a == par_b) 
            return;
        
        par[par_a] = par_b;
    }

    bool areSame(string &a, string &b) {
        if(a == b) return true;
        int diff = 0;
        for(int i=0; i<a.length(); i++) {
            if(a[i] != b[i]) {
                diff++;
            }
        }
        if(diff == 2) return true;
        return false;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        par.resize(n+1, -1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(areSame(strs[i], strs[j])) {
                    merge(i, j);
                }
            }
        }

        int root = 0;
        for(int i=0; i<n; i++) {
            if(par[i] < 0) {
                root++;
            }
        }
        return root;
    }
};
