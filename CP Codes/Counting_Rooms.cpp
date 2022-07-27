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

void dfs(int i, int j, vector<bool> &g, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (g[(i * m + j)] == false)
        return;

    g[(i * m + j)] = false;
    dfs(i - 1, j, g, n, m);
    dfs(i + 1, j, g, n, m);
    dfs(i, j - 1, g, n, m);
    dfs(i, j + 1, g, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> g(n * m, false);
    f(i, n)
    {
        f(j, m)
        {
            char c;
            cin >> c;
            if (c == '.')
                g[(i * m + j)] = true;
        }
    }
    int count = 0;
    f(i, n * m)
    {
        if (g[i])
        {
            dfs((i / m), (i % m), g, n, m);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}