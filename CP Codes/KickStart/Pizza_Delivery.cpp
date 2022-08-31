#include <bits/stdc++.h>
using namespace std;
#define v4 vector<vector<vector<vector<int>>>>
#define v3 vector<vector<vector<int>>>
#define v2 vector<vector<int>>
#define v1 vector<int>
char op[4];
int val[4];

int res(int i, int coins)
{
    switch (op[i])
    {
    case '+':
        return coins + val[i];
        break;
    case '-':
        return coins - val[i];
        break;
    case '*':
        return coins * val[i];
        break;
    case '/':
        return floor(coins / val[i]);
        break;
    }
    return 0;
}

bool possible = false;
int f(int i, int j, int p, int m, v2 arr, v4 dp)
{
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr.size())
        return 0;
    if (p == 0)
        possible = true;
    if (m == 0)
    {
        if (p == 0)
        {
            possible = true;
            return 0;
        }
        else
            return -1e9;
    }
    if (dp[i][j][p][m] != -1e9)
        return dp[i][j][p][m];

    int north1 = 0, east1 = 0, west1 = 0, south1 = 0, stay1 = -1e9;
    int north2 = 0, east2 = 0, west2 = 0, south2 = 0, stay2 = -1e9;

    if (p > 0)
    {
        north1 = res(0, arr[i][j] + f(i - 1, j, p - 1, m - 1, arr, dp));
        east1 = res(1, arr[i][j] + f(i, j + 1, p - 1, m - 1, arr, dp));
        west1 = res(2, arr[i][j] + f(i, j - 1, p - 1, m - 1, arr, dp));
        south1 = res(3, arr[i][j] + f(i + 1, j, p - 1, m - 1, arr, dp));
    }
    north2 = res(0, f(i - 1, j, p, m - 1, arr, dp));
    east2 = res(1, f(i, j + 1, p, m - 1, arr, dp));
    west2 = res(2, f(i, j - 1, p, m - 1, arr, dp));
    south2 = res(3, f(i + 1, j, p, m - 1, arr, dp));

    int max1 = max(north1, max(east1, max(west1, south1)));
    int max2 = max(north2, max(east2, max(west2, south2)));
    return dp[i][j][p][m] = max(max1, max2);
}
int main()
{
    int t, caseNo = 1;
    cin >> t;
    while (t--)
    {
        int n, m, p, x, y;
        cin >> n >> p >> m >> x >> y;
        for (int i = 0; i < 4; i++)
        {
            cin >> op[i] >> val[i];
        }

        v2 arr(n, v1(n, 0));
        v4 dp(n, v3(n, v2(p + 1, v1(m + 1, -1e9))));

        for (int i = 0; i < p; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            arr[a][b] = c;
        }

        int ans = f(x - 1, y - 1, p, m, arr, dp);
        if (possible && p <= m)
            cout << "Case #" << caseNo << ": " << ans << endl;
        else
            cout << "Case #" << caseNo << ": "
                 << "IMPOSSIBLE" << endl;
        caseNo++;
    }
}