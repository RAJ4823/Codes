#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
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

    ll n, m, ans = 0;
    cin >> n >> m;
    vll v(n), right(n, 0), left(n, 0);

    f(i, n) cin >> v[i];
    ff(i, 1, n) right[i] = right[i - 1] + max(0ll, (v[i - 1] - v[i]));
    fr(i, n - 2) left[i] = left[i + 1] + max(0ll, v[i + 1] - v[i]);

    while (m--)
    {
        ll x, y;
        cin >> x >> y;

        if (x < y)
            cout << right[--y] - right[--x] << endl;
        else
            cout << left[--y] - left[--x] << endl;
    }

    return 0;
}