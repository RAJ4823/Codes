// Link: https://leetcode.com/problems/path-with-minimum-effort

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-with-minimum-effort
 *  RUNTIME: 105 ms
 *  MEMORY: 20.3 MB
 *  DATE: 9-16-2023, 9:08:39 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> minEffort(n, vector<int> (m, INT_MAX));
        int dirs[5] = {-1, 0, 1, 0, -1};

        pq.push({0, {0, 0}});
        minEffort[0][0] = 0;

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int currEffort = pq.top().first;
            pq.pop();

            if(x == n-1 && y == m-1) {
                return currEffort;
            }

            for(int k=0; k<4; k++) {
                int row = x + dirs[k];
                int col = y + dirs[k+1];

                if(row >= 0 && col >= 0 && row < n && col < m) {
                    int newEffort = max(currEffort, abs(heights[x][y] - heights[row][col]));
                    if(newEffort < minEffort[row][col]) {
                        minEffort[row][col] = newEffort;
                        pq.push({newEffort, {row, col}});
                    }
                }
            }
        }
        return 0;
    }
};
