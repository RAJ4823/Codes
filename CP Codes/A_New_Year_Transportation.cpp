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

bool dfs(int s, int d, vector<int> g[])
{
    if (g[s][0] == d)
        return true;
    else if(s > d)
        return false;
    return dfs(g[s][0], d, g);
}
int main()
{
    int n, x, d;
    cin >> n >> x;

    vector<int> g[n];
    ff(i, 1, n)
    {
        cin >> d;
        g[i].push_back(i + d);
    }
    if (dfs(1, x, g))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}