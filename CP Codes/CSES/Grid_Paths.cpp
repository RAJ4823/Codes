#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define vvc vector<vector<char>>
#define vc vector<char>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll fun(int i, int j, vvc &grid, vvll &dp)
{
    if (i < 0 || j < 0 || grid[i][j] == '*')
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = (fun(i - 1, j, grid, dp) + fun(i, j - 1, grid, dp))%MOD;
}

int main()
{
    ll n;
    cin >> n;
    vvc grid(n, vc(n));
    vvll dp(n, vll(n, -1));

    f(i, n) f(j, n)
    {
        cin >> grid[i][j];
    }
    cout << fun(n - 1, n - 1, grid, dp);
    return 0;
}