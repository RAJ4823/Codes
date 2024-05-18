// Link: https://leetcode.com/problems/word-search-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-search-ii
 *  RUNTIME: 1160 ms
 *  MEMORY: 45.2 MB
 *  DATE: 4-3-2024, 1:26:02 PM
 *
 */

// Solution:

class Solution {
    HashMap<String,Integer> map = new HashMap<>();
    Set<String> ans = new HashSet<>();
    int max = -1;
    
    public List<String> findWords(char[][] board, String[] words) {
        for(int i=0;i<words.length;i++){
            map.put(words[i],1);
            max = Math.max(max,words[i].length());
        }

        int n=board.length;
        int m=board[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<board[i].length;j++){
                boolean vis[][]=new boolean[n][board[i].length];
                StringBuilder sb=new StringBuilder();
                dfs(i,j,sb,board,vis);
            }
        }
        return new ArrayList<>(ans);
    }

    void dfs(int i,int j,StringBuilder sb,char board[][],boolean vis[][]){
        if(i>=0 && i<board.length && j>=0 && j<board[0].length && vis[i][j]==false && sb.length()<max){
            sb.append(board[i][j]);
            String x=sb.toString();
             if(map.containsKey(x))
                ans.add(x);

            vis[i][j]=true;

            dfs(i+1,j,sb,board,vis);
            dfs(i,j+1,sb,board,vis);
            dfs(i-1,j,sb,board,vis);
            dfs(i,j-1,sb,board,vis);
            
            vis[i][j]=false;
            sb.deleteCharAt(sb.length()-1);
        }
        return;
    }
}
