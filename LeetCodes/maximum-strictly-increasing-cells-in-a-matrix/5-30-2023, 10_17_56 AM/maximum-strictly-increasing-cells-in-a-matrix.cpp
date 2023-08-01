// Link: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-strictly-increasing-cells-in-a-matrix
 *  RUNTIME: 1211 ms
 *  MEMORY: 241.7 MB
 *  DATE: 5-30-2023, 10:17:56 AM
 *
 */

// Solution:

class Solution {
 public:
  int maxIncreasingCells(vector<vector<int>>& mat) {
    int N = mat.size();
    int M = mat[0].size();
    vector<int> rows(N, 0); 
    vector<int> cols(M, 0); 
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<vector<int>> dist(N, vector<int>(M));
    set<int, greater<>> st;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            mp[mat[i][j]].push_back({i,j});
            st.insert(mat[i][j]);
        }
    }
      
    int ans = 0;
    for (auto &val: st) {
        for (auto &[row, col] : mp[val]) {
            dist[row][col] = 1 + max(rows[row], cols[col]);
        }
        for (auto &[row, col] : mp[val]) {
            rows[row] = max(rows[row], dist[row][col]);
            cols[col] = max(cols[col], dist[row][col]);
            ans = max({ans, rows[row], cols[col]});
        }
    }

    return ans;
  }
};
