#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define vvll vector<vll>
#define mll map<ll, ll>
#define mvll map<ll, vll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define fauto(i, x) for (auto i : x)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL
#define FUCodeChef return 0

void max_sum(ll x, ll p, ll prev, ll &ans, vpll &cp, mvll &graph)
{
    // Calculating maximum sum of gcd possible
    ans = max(ans, prev);
    fauto(&i, graph[x])
    {
        if (i != p)
        {
            ll curr = prev + (cp[i].first - cp[i].second);
            max_sum(i, x, curr, ans, cp, graph);
        }
    }
}

ll dfs_gcd(ll x, ll p, vll &val, vpll &cp, mvll &graph)
{

    // Child = gcd of child
    // Parent = final gcd of parent
    ll final = 0, sum = val[x];

    fauto(&i, graph[x])
    {
        if (i != p)
        {
            ll prev = dfs_gcd(i, x, val, cp, graph);
            sum = __gcd(sum, prev);
            final += prev;
        }
    }

    cp[x].first = final;
    cp[x].second = sum;
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;
        mvll graph;
        vll val(n);
        vpll cp(n);

        f(i, n) cin >> val[i];
        f(i, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        ll temp = dfs_gcd(0, -1, val, cp, graph);
        max_sum(0, -1, cp[0].first, ans, cp, graph);

        // fauto(i, child) cout << i << ' ';
        // cout << endl;
        // fauto(i, parent) cout << i << ' ';
        // cout << endl;
        cout << ans << endl;
    }
    FUCodeChef;
}