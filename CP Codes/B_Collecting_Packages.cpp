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

#define vbool vector<bool>
#define vvbool vector<vbool>

void solve(int n, vpll &v)
{
    string ans = "";
    pll last = {0, 0};
    f(i, n)
    {
        int move_r = v[i].first - last.first;
        int move_u = v[i].second - last.second;
        if (move_r < 0 || move_u < 0)
        {
            cout << "NO\n";
            return;
        }
        ans += string(move_r, 'R');
        ans += string(move_u, 'U');
        last = v[i];
    }
    cout << "YES\n";
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vpll v(n);
        f(i, n) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        solve(n, v);
    }
    return 0;
}
