#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL
// LINK : https://leetcode.com/problems/surrounded-regions/

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

int main()
{
    int n, m;
    cin >> n >> m;
    char c;
    vector<vector<char>> board;
    f(i, n)
    {
        vector<char> temp;
        f(j, m)
        {
            cin >> c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }
    solve(board);
    f(i, n)
    {
        f(j, m)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}