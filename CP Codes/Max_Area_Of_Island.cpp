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
// LINK : https://leetcode.com/problems/max-area-of-island/

void dfs(int i, int j, int &count, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return;
    if (grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    count++;

    dfs(i + 1, j, count, grid);
    dfs(i - 1, j, count, grid);
    dfs(i, j + 1, count, grid);
    dfs(i, j - 1, count, grid);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int ans = 0, count = 0;
    f(i, grid.size())
    {
        f(j, grid[0].size())
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, count, grid);
                ans = max(ans, count);
                count = 0;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int c, ans = 0;
    vector<vector<int>> grid;
    f(i, n)
    {
        vector<int> temp;
        f(j, m)
        {
            cin >> c;
            temp.push_back(c);
        }
        grid.push_back(temp);
    }
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}