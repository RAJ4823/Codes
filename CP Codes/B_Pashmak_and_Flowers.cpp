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
    ll n, x, mini = INT_MAX, maxi = 0;
    cin >> n;
    mll m;
    f(i, n)
    {
        cin >> x;
        m[x]++;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    ll ans = 0;
    if (maxi == mini)
        ans = (n * (n - 1)) / 2;
    else
        ans = (m[maxi] * m[mini]);
    cout << (maxi - mini) << ' ' << ans << endl;
    return 0;
}