// ⭐ the_247 | Raj Patel ⭐
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define pqll priority_queue<ll>
#define umll unordered_map<ll, ll>
#define usll unordered_set<ll>
#define mll map<ll, ll>
#define sll set<ll>

#define fauto(i, a) for (auto &i : a)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)

#define all(x) (x).begin(), (x).end()
#define sortv(v) sort(all(v))
#define sortvd(v) sort(all(v), greater<>());
#define sortstr(str) sort(all(str))
#define sortstrd(str) sort(all(str), greater<char>())
#define tolowerstr(str) transform(all(str), str.begin(), ::tolower)
#define toupperstr(str) transform(all(str), str.begin(), ::toupper)
#define print_condition(x, s1, s2) cout << ((x) ? s1 : s2) << endl;
#define print_vector(v) fauto(x, v) cout << (x) << ' ';

#define db(x) cout << (#x) << " = " << x << "\n";
#define dbb(x, y) cout << (#x) << " = " << x << " , " << (#y) << " = " << y << "\n"

#define PI 3.1415926535897932384626433832795
#define INF LONG_LONG_MAX
#define MOD 1000000007LL
#define MODD 998244353

vpll find(vll &a, ll n)
{
    ll maxi = -50, mini = 50;
    ll pos = 0, neg = 0;
    ll maxi_index = 0, mini_index = 0;
    vpll ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            maxi_index = i + 1;
        }
        if (a[i] < mini)
        {
            mini = a[i];
            mini_index = i + 1;
        }
    }

    if (n == 1 || maxi == mini)
        return {};

    if (maxi == 0)
    {
        fr(i, n - 2, 0) ans.push_back({i + 1, i + 2});
        return ans;
    }

    if (mini == 0)
    {
        f(i, 0, n - 1) ans.push_back({i + 2, i + 1});
        return ans;
    }

    if (maxi < abs(mini))
    {
        f(i, 0, n)
        {
            if (mini != a[i] && a[i] > 0)
            {
                ans.push_back({i + 1, mini_index});
                a[i] += mini;
            }
        }
        fr(i, n - 2, 0) ans.push_back({i + 1, i + 2});
        return ans;
    }

    f(i, 0, n)
    {
        if (maxi != a[i] && a[i] < 0)
        {
            ans.push_back({i + 1, maxi_index});
            a[i] += maxi;
        }
    }
    f(i, 0, n - 1) ans.push_back({i + 2, i + 1});
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vll v(n);
        f(i, 0, n) cin >> v[i];
        vpll ans = find(v, n);

        cout << ans.size() << endl;
        fauto(x, ans) cout << x.first << ' ' << x.second << endl;
        // print_vector(v);
        // cout << endl;
    }
    return 0;
}
