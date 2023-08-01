// Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-closest-node-to-given-two-nodes
 *  RUNTIME: 235 ms
 *  MEMORY: 96.3 MB
 *  DATE: 1-25-2023, 10:05:37 AM
 *
 */

// Solution:

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        int n = edges.size(), ans = n+1;
        vector<int> visitor(n, -1);

        queue<pair<int,int>> q;
        q.push({node1, 0});
        q.push({node2, 0});
        visitor[node1] = node1;
        visitor[node2] = node2;
        int minStep = -1;

        while(!q.empty()) {
            int node = q.front().first;
            int step = q.front().second;
            q.pop();

            if(minStep != -1 && step > minStep)
                break;

            int next = edges[node];
            if(next != -1) {
                if(visitor[next] == -1) {
                    visitor[next] = visitor[node];
                    q.push({next, step + 1});
                } else if(visitor[next] != visitor[node] && (minStep == -1 || step == minStep)) {
                    if(minStep == -1) minStep = step;
                    ans = min(ans, next);
                }
            }
        }
        if(ans == n+1) return -1;
        return ans;
    }
};
