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
    ll n, x;
    cin >> n;
    vll a(n), b(n);
    mll m, index;
    f(i, n) cin >> a[i];
    f(i, n)
    {
        cin >> x;
        index[x] = i;
    }
    f(i, n)
    {
        ll steps = 0;
        if (index[a[i]] > i)
            steps = (n - index[a[i]]) + i;
        else
            steps = (i - index[a[i]]);
        m[steps]++;
    }
    ll maxi = 0;
    fauto(val, m) maxi = max(maxi, val.second);
    cout << maxi << endl;
    return 0;
}