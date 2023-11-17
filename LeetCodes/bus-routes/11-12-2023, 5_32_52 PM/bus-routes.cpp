// Link: https://leetcode.com/problems/bus-routes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: bus-routes
 *  RUNTIME: 539 ms
 *  MEMORY: 57.7 MB
 *  DATE: 11-12-2023, 5:32:52 PM
 *
 */

// Solution:

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;

        int n = routes.size(), buses = 0;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++) {
            for(auto &stop: routes[i]) {
                adj[stop].push_back(i);
            }
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(source);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int currStop = q.front();
                q.pop();

                if(currStop == target)
                    return buses;
                for(auto &route: adj[currStop]) {
                    if(!vis[route]) {
                        vis[route] = true;
                        for(auto &stop: routes[route]) {
                            q.push(stop);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};
