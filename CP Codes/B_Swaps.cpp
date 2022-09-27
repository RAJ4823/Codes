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
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll a(n), b(n);
        mll ai, bi;
        f(i, n)
        {
            cin >> a[i];
            ai[(a[i] + 1) / 2] = i;
        }
        f(i, n)
        {
            cin >> b[i];
            bi[b[i] / 2] = i;
        }
        bi[n + 1] = INT_MAX;
        ffr(i, n, 1)
        {
            bi[i] = min(bi[i], bi[i + 1]);
        }
        ll ans = INT_MAX;
        ff(i, 1, n + 1)
        {
            ans = min(ans, ai[i] + bi[i]);
        }
        cout << ans << endl;
    }
    return 0;
}