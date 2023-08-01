// Link: https://leetcode.com/problems/snakes-and-ladders

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: snakes-and-ladders
 *  RUNTIME: 30 ms
 *  MEMORY: 14.3 MB
 *  DATE: 1-24-2023, 11:17:15 AM
 *
 */

// Solution:

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> columns(n);
        vector<pair<int, int>> pos;
        pos.push_back({0,0}); // temp
        
        iota(columns.begin(), columns.end(), 0);
        
        for (int row = n - 1; row >= 0; row--) {
            for (int col : columns)
                pos.push_back({row, col});
            reverse(columns.begin(), columns.end());
        }

        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = curr + 1; i <= min(curr + 6, n * n); i++) {
                auto [row, col] = pos[i];
                int next = board[row][col] != -1 ? board[row][col] : i;
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return dist[n * n];
    }
};
