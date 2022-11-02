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
    ll n, m;
    cin >> n >> m;
    if (m <= n)
    {
        cout << (n - m) << endl;
    }
    else
    {
        ll cnt1 = 0, cnt2 = 0;
        ll x = n, y = m;
        while (x < m)
        {
            x *= 2;
            cnt1++;
        }
        cnt1 += (x - m);
        while (n < y && y % 2 == 0)
        {
            y /= 2;
            cnt2++;
        }
        if (y < n)
            cnt2 += (n - y);
        else
            cnt2 = INT_MAX;
        db2(cnt1, cnt2);
        cout << min(cnt1, cnt2) << endl;
    }
    return 0;
}