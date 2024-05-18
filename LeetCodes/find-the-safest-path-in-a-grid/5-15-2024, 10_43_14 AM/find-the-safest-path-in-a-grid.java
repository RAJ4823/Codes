// Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-safest-path-in-a-grid
 *  RUNTIME: 182 ms
 *  MEMORY: 70.2 MB
 *  DATE: 5-15-2024, 10:43:14 AM
 *
 */

// Solution:

class Solution {
    int n, m;
    int[] dirs = new int[]{-1, 0, 1, 0, -1};

    public int[][] fillSafeness(List<List<Integer>> grid) {
        int[][] safeness = new int[n][m];
        Queue<int[]> q = new LinkedList<>();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid.get(i).get(j) == 1) {
                    safeness[i][j] = 0;
                    q.add(make_pair(i, j));
                } else {
                    safeness[i][j] = n * m;
                }
            }
        }

        while(!q.isEmpty()) {
            int[] node = q.remove();
            int x = node[0];
            int y = node[1];

            for(int k=0; k<4; k++) {
                int i = x + dirs[k];
                int j = y + dirs[k+1];

                if(i < 0 || j < 0 || i >= n || j >= n || safeness[i][j] <= 1 + safeness[x][y])
                    continue;
                q.add(make_pair(i, j));
                safeness[i][j] = 1 + safeness[x][y];
            }
        }
        return safeness;
    }

    public int findMaxSafeness(int[][] safeness, List<List<Integer>> grid) {
        Queue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                if(a[0] == b[0]) return 0;
                return a[0] > b[0] ? -1 : 1;
            }
        });
        boolean[][] vis = new boolean[n][m];

        pq.add(make_pair(safeness[0][0], 0, 0));
        vis[0][0] = true;

        while(!pq.isEmpty()) {
            int[] node = pq.remove();
            int x = node[1];
            int y = node[2];

            for(int k=0; k<4; k++) {
                int i = x + dirs[k];
                int j = y + dirs[k+1];

                if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j])
                    continue;
                
                vis[i][j] = true;
                safeness[i][j] = Math.min(safeness[i][j], safeness[x][y]);
                pq.add(make_pair(safeness[i][j], i, j));
            }
        }
        return safeness[n-1][m-1]; 
    }

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        n = grid.size();
        m = grid.get(0).size();
        if(grid.get(0).get(0) == 1 || grid.get(n-1).get(m-1) == 1)
            return 0;
            
        int[][] safeness = fillSafeness(grid);
        int ans = findMaxSafeness(safeness, grid);
        return ans;
    }

    public int[] make_pair(int a, int b) {
        return new int[]{a, b};
    }
    public int[] make_pair(int a, int b, int c) {
        return new int[]{a, b, c};
    }
}
