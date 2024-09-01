// Link: https://leetcode.com/problems/count-sub-islands

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-sub-islands
 *  RUNTIME: 19 ms
 *  MEMORY: 85.8 MB
 *  DATE: 8-28-2024, 9:43:07 AM
 *
 */

// Solution:

class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int m = grid2.length;
        int n = grid2[0].length;
        int subIslandsCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell in grid2 is land, check if it forms a sub-island.
                if (grid2[i][j] == 1) {
                    // Start DFS and check if it's a valid sub-island.
                    if (dfs(grid1, grid2, i, j)) {
                        subIslandsCount++;
                    }
                }
            }
        }

        return subIslandsCount;
    }
    private boolean dfs(int[][] grid1, int[][] grid2, int i, int j) {
        int m = grid2.length;
        int n = grid2[0].length;

        // Base case: if out of bounds or the cell is water, stop recursion.
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return true;
        }

        // Mark the current cell as visited in grid2.
        grid2[i][j] = 0;

        // Check if the current cell is not part of a sub-island (i.e., if grid1 has water where grid2 has land).
        boolean isSubIsland = grid1[i][j] == 1;

        // Explore all 4 possible directions (up, down, left, right).
        isSubIsland &= dfs(grid1, grid2, i + 1, j);
        isSubIsland &= dfs(grid1, grid2, i - 1, j);
        isSubIsland &= dfs(grid1, grid2, i, j + 1);
        isSubIsland &= dfs(grid1, grid2, i, j - 1);

        return isSubIsland;
    }
}
