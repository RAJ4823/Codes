// Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-path-with-different-adjacent-characters
 *  RUNTIME: 407 ms
 *  MEMORY: 162.1 MB
 *  DATE: 1-13-2023, 6:55:02 PM
 *
 */

// Solution:

class Solution {
public:
    
    int ans = 1;
    int dfs(int node, vector<int> adj[], string &s) {
        if(adj[node].empty()) return 1;

        int firstMax = 0, SecondMax =0;
        int maxLen = 0;
        for(auto &x : adj[node])
        {
            int currLen = dfs(x, adj, s);
            maxLen = max(currLen, maxLen);

            if(s[node] != s[x]) {
                if(currLen > firstMax){
                    SecondMax = firstMax;
                    firstMax = currLen;
                }
                else {
                    SecondMax = max(SecondMax , currLen);
                } 
            }
        }

        int total = 1 + firstMax + SecondMax;
        ans = max(ans, max(maxLen, total));
        return (1 + firstMax);
    }
    int longestPath(vector<int>& par, string s) {
        int n = par.size();
        vector<int> adj[n];
        for(int i=1; i<n; i++) {
            adj[par[i]].push_back(i);
        }

        int temp = dfs(0, adj, s);
        return ans;
    }
};
