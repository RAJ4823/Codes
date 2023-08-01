// Link: https://leetcode.com/problems/shortest-path-to-get-all-keys

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-path-to-get-all-keys
 *  RUNTIME: 255 ms
 *  MEMORY: 56.3 MB
 *  DATE: 6-29-2023, 11:42:34 AM
 *
 */

// Solution:


class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<vector<int>> q;
        unordered_map<char, int> keyBit;    // Denotes the bit location of char

        int bit = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '@') {
                    q.push({i, j, 0}); // keyState: 000000
                }

                if(islower(grid[i][j])) {
                    keyBit[grid[i][j]] = bit++;
                }
            }
        }

        int mask_end = (1 << bit) - 1;
        int mask_size = (1 << bit);
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (mask_size, false)));

        int dirs[5] = {-1,0,1,0,-1};
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int row = q.front()[0];
                int col = q.front()[1];
                int mask = q.front()[2];
                q.pop();
                
                if(row < 0 || row>=n || col < 0 || col >=m || grid[row][col] == '#')
                    continue;
                    
                int key = (1 << keyBit[tolower(grid[row][col])]);
                // Check if the key is required but not collected
                if(isupper(grid[row][col]) && (mask & key) == 0) continue;
                
                // If the position contains key, collect it
                if(islower(grid[row][col]))     mask = mask | key;

                // If all keys are collected, return steps
                if(mask == mask_end)        return steps;

                // If position and mask already visited, continue to next iteration
                if(vis[row][col][mask]) continue;

                vis[row][col][mask] = true;
                q.push({row+1, col, mask});
                q.push({row-1, col, mask});
                q.push({row, col+1, mask});
                q.push({row, col-1, mask});
                
            }
            steps++;
        }
        return -1;
    }
};
