// Link: https://leetcode.com/problems/word-search

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-search
 *  RUNTIME: 164 ms
 *  MEMORY: 41.6 MB
 *  DATE: 4-3-2024, 1:01:07 PM
 *
 */

// Solution:

class Solution {
    public static int n = 0;
    public static int m = 0;
    public static int l = 0;
    public static int[] dist = {-1, 0, 1, 0, -1};

    public boolean dfs(int i, int j, int k, boolean[][] vis, char[][] board, String word) {
        if(board[i][j] != word.charAt(k))
            return false;
        if(board[i][j] == word.charAt(k) && k == l - 1)
            return true;

        vis[i][j] = true;

        for(int d = 0; d < 4; d++) {
            int x = i + dist[d];
            int y = j + dist[d + 1];
            
            if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && k + 1 < l) {
                if(dfs(x, y, k + 1, vis, board, word)) {
                    return true;
                }
            }
        }
        
        vis[i][j] = false;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        char start = word.charAt(0);
        l = word.length();
        n = board.length;
        m = board[0].length;


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == start) {
                    boolean[][] vis = new boolean[n][m];
                    if(dfs(i, j, 0, vis, board, word)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
}
