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
const int mod = 1000000007;

ll power(ll a, ll b)
{
    if (!b)
        return 1;
    if (b % 2)
        return a * power(a, b - 1) % mod;
    return power(a * a % mod, b / 2);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    if (k == 1)
    {
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());
    vll v(n);
    ll sum = 0;

    --k;
    v[k] = 1;
    ff(i, k + 1, n)
        v[i] = v[i - 1] * i % mod * power(i - k, mod - 2) % mod;

    f(i, n)
    {
        sum += a[i] * v[i];
        sum -= a[i] * v[n - 1 - i];
        sum %= mod;
        (sum += mod) %= mod;
    }

    cout << sum << endl;

    return 0;
}