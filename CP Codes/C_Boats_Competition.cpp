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
        ll cnt[2 * n + 1] = {0};

        f(i, n)
        {
            ll x;
            cin >> x;
            cnt[x]++;
        }
        ll ans = 0;
        ff(sum, 2, (2 * n + 1))
        {
            ll maxi = 0;
            if (sum % 2 == 0)
                maxi += cnt[sum / 2] / 2;
            for (int i = 1; i < (sum + 1) / 2; i++)
            {
                if (sum - i > n)
                    continue;
                maxi += min(cnt[i], cnt[sum - i]);
            }
            ans = max(ans, maxi);
        }
        cout << ans << endl;
    }
    return 0;
}