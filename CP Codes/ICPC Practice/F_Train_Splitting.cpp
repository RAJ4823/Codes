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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vpll edges;
        vll degree(n + 1);

        f(i, m)
        {
            ll u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            degree[u]++;
            degree[v]++;
        }

        ll colors = 0, vertex;
        vll c(m);
        pll temp1 = {1, 2};
        pll temp2 = {2, 1};

        ff(i, 1, n + 1)
        {
            if (degree[i] != n - 1)
            {
                vertex = i;
                break;
            }
        }

        // IF GRAPH IS FULLY CONNECTED - MIN COLOR REQUIRED = 3
        if (m * 2 == (n * (n - 1)))
        {
            colors = 3;
            f(i, m)
            {
                if (edges[i] == temp1 || edges[i] == temp2)
                    c[i] = 1;
                else if (edges[i].first == 1 || edges[i].second == 1)
                    c[i] = 2;
                else
                    c[i] = 3;
            }
        }
        // MIN COLOR REQUIRED = 2
        else
        {
            colors = 2;
            f(i, m)
            {
                if (edges[i].first == vertex || edges[i].second == vertex)
                    c[i] = 1;
                else
                    c[i] = 2;
            }
        }

        cout << colors << endl;
        f(i, m) cout << c[i] << ' ';
        cout << endl;
    }
    return 0;
}