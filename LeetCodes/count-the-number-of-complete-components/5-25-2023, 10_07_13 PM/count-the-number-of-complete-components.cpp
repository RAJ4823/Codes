// Link: https://leetcode.com/problems/count-the-number-of-complete-components

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-the-number-of-complete-components
 *  RUNTIME: 264 ms
 *  MEMORY: 132.6 MB
 *  DATE: 5-25-2023, 10:07:13 PM
 *
 */

// Solution:

class Solution {
public:
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        vector<int> ind(n, 0);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            ind[u]++;
            ind[v]++;
        }
        
        
        int countComplete = 0;
        for(int i=0; i<n; i++) {
            if(vis[i]) continue;
            
            queue<int> q;
            vector<int> comp;
            vis[i] = true;
            q.push(i);

            while(!q.empty()) {
                int node = q.front();
                comp.push_back(node);
                q.pop();
                
                for(auto &next: graph[node]) {
                    if(!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            
            bool isComplete = true;
            int deg = comp.size() - 1;
            for(auto &x: comp) {
                // printf("(%d , %d)\n", x, ind[x]);
                if(ind[x] != deg) {
                    isComplete = false;
                    break;
                }
            }
            countComplete += isComplete;
        }
        return countComplete;
    }
};
