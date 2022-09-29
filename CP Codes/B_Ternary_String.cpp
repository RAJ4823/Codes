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

//! Kind of DP
vpll fillValues(string &s)
{
    vpll v;
    ll count[4] = {0};
    ll curr, prev = (s[0] - '0');
    count[prev] = 1;
    ff(i, 1, s.length())
    {
        curr = (s[i] - '0');
        if (count[curr] == 0)
        {
            v.push_back({prev, count[prev]});
            count[prev] = 0;
        }
        count[curr]++;
        prev = curr;
    }
    v.push_back({prev, count[prev]});
    return v;
}

ll getAns(vpll &v, ll n, ll max)
{
    ll ans = max;
    ff(i, 1, n - 1)
    {
        if (v[i - 1].first != v[i + 1].first)
            ans = min(ans, (v[i].second + 2));
    }
    return (ans == max) ? (0) : (ans);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.length();

        vpll num = fillValues(s);
        ll ans = getAns(num, num.size(), n + 1);

        cout << ans << endl;
    }
    return 0;
}