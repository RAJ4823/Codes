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

void input(ll n, vll &val, mvll &graph)
{
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
}

void max_sum(ll x, ll p, ll prev, ll &ans, vll &child, vll &parent, mvll &graph)
{
    // Calculating maximum sum of gcd possible
    ans = max(ans, prev);
    fauto(&i, graph[x])
    {
        if (i == p)
            continue;

        ll curr = prev + (parent[i] - child[i]);
        max_sum(i, x, curr, ans, child, parent, graph);
    }
}

ll dfs_gcd(ll x, ll p, vll &val, vll &child, vll &parent, mvll &graph)
{

    // Child = gcd of child
    // Parent = final gcd of parent
    ll final = 0, curr = val[x];

    fauto(&i, graph[x])
    {
        if (i == p)
            continue;

        ll prev = dfs_gcd(i, x, val, child, parent, graph);
        curr = __gcd(curr, prev);
        final += prev;
    }

    parent[x] = final;
    child[x] = curr;
    return curr;
}

ll solve(ll n, vll &val, mvll &graph)
{
    ll ans = 0;
    vll child(n), parent(n);

    dfs_gcd(0, -1, val, child, parent, graph);
    max_sum(0, -1, parent[0], ans, child, parent, graph);

    // fauto(i, child) cout << i << ' ';
    // cout << endl;
    // fauto(i, parent) cout << i << ' ';
    // cout << endl;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        mvll graph;
        vll val(n);

        input(n, val, graph);
        cout << solve(n, val, graph) << endl;
    }
    FUCodeChef;
}