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

int dfs(int i, int j, vector<vector<int>> &grid)
{
    int perimeter = 0;
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 1;
    if (grid[i][j] == 0)
        return 1;
    if (grid[i][j] == 1)
    {
        grid[i][j] = -1;
        perimeter += dfs(i - 1, j, grid);
        perimeter += dfs(i + 1, j, grid);
        perimeter += dfs(i, j - 1, grid);
        perimeter += dfs(i, j + 1, grid);
    }
    return perimeter;
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int ans = 0;

    f(i, grid.size())
        f(j, grid[0].size()) if (grid[i][j] == 1)
            ans += dfs(i, j, grid);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    f(i, n)
    {
        vector<int> temp(m, 0);
        f(j, m)
        {
            cin >> temp[j];
        }
        grid.push_back(temp);
    }
    cout << islandPerimeter(grid) << endl;
    return 0;
}