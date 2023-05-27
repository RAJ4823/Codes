#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
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

void dfs(int i, vector<set<int>> &graph, vll &vis, vvll &group)
{
    vis[i] = true;
    group.back().push_back(i);
    for (auto &next : graph[i])
    {
        if (!vis[next])
        {
            dfs(next, graph, vis, group);
        }
    }
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<set<int>> graph(n);
        vvll group;
        vll deg(n, 0);
        vll vis(n, false);

        f(i, n)
        {
            ll x;
            cin >> x;
            x--;
            graph[x].insert(i);
            graph[i].insert(x);
        }

        f(i, n)
        {
            deg[i] = graph[i].size();
        }

        ll mini = 0, maxi = 0, cnt = 0;
        f(i, n)
        {
            if (!vis[i])
            {
                vll empty;
                group.push_back(empty);
                dfs(i, graph, vis, group);
                maxi++;
            }
        }

        ll cycle = 0, line = 0;
        for (auto &comp : group)
        {
            bool flag = false;
            for (auto &i : comp)
            {
                if (deg[i] == 1)
                {
                    flag = true;
                    line++;
                    break;
                }
            }
            if (!flag)
                cycle++;
        }
        mini = cycle + min(line, 1ll);
        cout << mini << ' ' << maxi << endl;
    }
    return 0;
}