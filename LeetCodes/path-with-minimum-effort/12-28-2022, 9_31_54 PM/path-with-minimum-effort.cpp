// Link: https://leetcode.com/problems/path-with-minimum-effort

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-with-minimum-effort
 *  RUNTIME: 142 ms
 *  MEMORY: 19.9 MB
 *  DATE: 12-28-2022, 9:31:54 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size();
        int m = heights[0].size();

        // MinHeap PQ: {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return diff;
            for (int k = 0; k < 4; k++)
            {
                int newr = row + dx[k];
                int newc = col + dy[k];
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // new diff of heights and newEfforts will be the max of (previous diff and new diff)
                    int newDiff = abs(heights[newr][newc] - heights[row][col]);
                    int newEffort = max(diff, newDiff);
                    if (newEffort < effort[newr][newc])
                    {
                        effort[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};
