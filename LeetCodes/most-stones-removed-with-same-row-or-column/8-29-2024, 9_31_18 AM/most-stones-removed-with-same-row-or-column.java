// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-stones-removed-with-same-row-or-column
 *  RUNTIME: 54 ms
 *  MEMORY: 45.3 MB
 *  DATE: 8-29-2024, 9:31:18 AM
 *
 */

// Solution:

class Solution {
    int n;
    public int removeStones(int[][] stones) {
        n = stones.length;
        int group = 0;

        int[] vis = new int[n];
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(i, stones, vis);
                group++;
            }
        }

        return n - group;
    }

    void dfs(int i, int[][] stones, int[] vis) {
        vis[i] = 1;
        for(int j=0; j<n; j++) {
            if(vis[j] == 0) {
                if(stones[j][0] == stones[i][0])
                    dfs(j, stones, vis);
                if(stones[j][1] == stones[i][1])
                    dfs(j, stones, vis);
            }
        }
    }
}
