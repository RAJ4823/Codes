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

ll BFS(vvll &graph, int n, int q)
{
    vector<int> parent(n + 1, -1);
    queue<int> que;
    que.push(1);

    int ans = 1;

    while (!que.empty())
    {
        int nodes = que.size();
        q -= nodes;
        if (q >= 0)
        {
            ans += nodes;
            for (int i = 0; i < nodes; i++)
            {
                int curr = que.front();
                que.pop();
                for (auto x : graph[curr])
                {
                    if (x != parent[curr])
                    {
                        que.push(x);
                        parent[x] = curr;
                    }
                }
            }
            continue;
        }
        break;
    }
    return (ans - 1);
}

int main()
{
    int t;
    cin >> t;

    f(caseNo, t)
    {

        int n, q;
        cin >> n >> q;

        vvll graph(n + 1);
        int x, y;
        f(i, n - 1)
        {
            cin >> x >> y;
            graph[y].push_back(x);
            graph[x].push_back(y);
        }

        int temp;
        f(i, q) cin >> temp;

        ll ans = BFS(graph, n, q);
        cout << "Case #" << caseNo + 1 << ": " << ans << endl;
    }
    return 0;
}