// Link: https://leetcode.com/problems/keys-and-rooms

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: keys-and-rooms
 *  RUNTIME: 19 ms
 *  MEMORY: 11.2 MB
 *  DATE: 12-20-2022, 12:50:49 PM
 *
 */

// Solution:

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> graph[n];

        for(int i=0; i<n; i++) {
            for(auto &x: rooms[i]) {
                graph[i].push_back(x);
            }
        }

        queue<int> q;
        vector<int> vis(n, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &x: graph[node]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
