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
        ll n, k, x;
        cin >> n >> k;
        mll m;
        f(i, n)
        {
            cin >> x;
            if (x % k)   m[k - x % k]++;
        }

        ll ans = 0, maxi = -1;
        fauto(i, m)
        {
            if (i.second >= maxi)
            {
                maxi = i.second;
                ans = k * (maxi - 1) + i.first + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}