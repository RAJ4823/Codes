// Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: lexicographically-smallest-equivalent-string
 *  RUNTIME: 24 ms
 *  MEMORY: 7.3 MB
 *  DATE: 1-14-2023, 9:47:57 AM
 *
 */

// Solution:

class Solution {
public:
    // char mini;
    int dfs(int s, vector<int> adj[], int vis[]) {
        vis[s] = 1;
        int mini = s;
        for(auto &ch: adj[s]) {
            if(!vis[ch]) {
                int temp = dfs(ch, adj, vis);
                mini = min(mini, temp);
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<int> adj[26];
        for(int i=0; i<n; i++) {
            int u = (int)(s1[i] - 'a');
            int v = (int)(s2[i] - 'a');
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // for(int i=0; i<26; i++) {
        //     if(adj[i].empty()) continue;
        //     cout << (char)(i + 'a') << " = ";
        //     for(auto &y : adj[i]) {
        //         cout << (char)(y + 'a') << ' ';
        //     }
        //     cout << endl;
        // }

        string ans = "";
        for(auto &ch: baseStr) {
            int s = (int)(ch - 'a');
            int vis[26] = {};
            ans += (char)(dfs(s, adj, vis) + 'a');
        }
        return ans;
    }
};
