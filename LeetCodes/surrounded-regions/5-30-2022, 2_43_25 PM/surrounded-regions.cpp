// Link: https://leetcode.com/problems/surrounded-regions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: surrounded-regions
 *  RUNTIME: 12 ms
 *  MEMORY: 10 MB
 *  DATE: 5-30-2022, 2:43:25 PM
 *
 */

// Solution:

#define f(i, n) for (int i = 0; i < (n); i++)
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, char ch)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return;

    if (board[i][j] == 'X')
        return;
    if (ch == 'O')
    {
        if (board[i][j] == 'A')
            return;
        board[i][j] = 'A';
    }
    if (ch == 'A')
    {
        if (board[i][j] == 'O')
            return;
        board[i][j] = 'O';
    }

    dfs(i + 1, j, board, ch);
    dfs(i - 1, j, board, ch);
    dfs(i, j + 1, board, ch);
    dfs(i, j - 1, board, ch);
}

void convert1(vector<vector<char>> &board, char ch)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        dfs(i, 0, board, ch);
        dfs(i, m - 1, board, ch);
    }
    for (int i = 0; i < m; i++)
    {
        dfs(0, i, board, ch);
        dfs(n - 1, i, board, ch);
    }
}

void solve(vector<vector<char>> &board)
{
    // convert1 & DFS: Running dfs for boarder and marking group of O's that are connected to boarder '+'
    // convert2 : After that marking all remaining 'O' to 'X'
    // convert1 & DFS : Convert all '+' to 'O;
    convert1(board, 'O'); // Will convert 'O' -> 'A'

    f(i, board.size())
    {
        f(j, board[0].size())
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    
    convert1(board, 'A'); // Will convert 'A' -> 'O'
}
};
