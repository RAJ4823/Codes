// Link: https://leetcode.com/problems/path-with-minimum-effort

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-with-minimum-effort
 *  RUNTIME: 39 ms
 *  MEMORY: 45 MB
 *  DATE: 5-15-2024, 5:51:46 PM
 *
 */

// Solution:

class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;

        Queue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] == b[0]) return 0;
                return (a[0] > b[0]) ? 1 : -1;
            }
        });
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        int[][] efforts = new int[n][m];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) efforts[i][j] = Integer.MAX_VALUE;

        efforts[0][0] = 0;
        pq.add(make_pair(0, 0, 0));

        while(!pq.isEmpty()) {
            int[] node = pq.remove();
            int currEffort = node[0];
            int x = node[1];
            int y = node[2];

            if(x == n-1 && y == m-1)
                return currEffort;

            for(int k=0; k<4; k++) {
                int i = x + dirs[k];
                int j = y + dirs[k+1];

                if(i<0 || j<0 || i>=n || j>=m)
                    continue;
                int resEffort = Math.max(currEffort, Math.abs(heights[i][j] - heights[x][y]));
                if(resEffort < efforts[i][j]) {
                    efforts[i][j] = resEffort;
                   pq.add(make_pair(resEffort, i, j));
                }
            }
        }
        return -1;
    }

    public int[] make_pair(int a, int b, int c) {
        return new int[]{a, b, c};
    }
}
