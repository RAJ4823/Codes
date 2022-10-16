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

int modulo(int a, int n = MOD)
{
    int q = (int)floor((double)a / n);
    return a - n * q;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    ll n;
    cin >> n;
    ll ans[6] = {x - y, x, y, y - x, -x, -y};
    f(i, 6) ans[i] = modulo(ans[i]);
    cout << ans[n % 6] << endl;
    return 0;
}