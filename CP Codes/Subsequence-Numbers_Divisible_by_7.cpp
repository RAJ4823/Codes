#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (ll i = 0; i < (n); i++)
#define ff(i, a, b) for (ll i = (a); i < (b); i++)
#define fr(i, n) for (ll i = (n); i >= 0; i--)
#define ffr(i, a, b) for (ll i = (a); i >= (b); i--)
#define yn(x) (x) ? cout << "YES\n" : cout << "NO\n";
#define ynif(x, y) (x == y) ? cout << "YES\n" : cout << "NO\n";
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

void update(vector<vector<ll>> &v, ll i, ll num, ll dig)
{
    // updating values of v
    // num = whole number
    // dig = current digit
    f(j, 7)
    {
        ll k = (j * num + dig) % 7;
        // db1(k);
        v[i + 1][j] = (v[i + 1][j] + v[i][j]) % MOD;
        v[i + 1][k] = (v[i + 1][k] + v[i][j]) % MOD;
    }
}

ll ans(vector<vector<ll>> &v)
{
    // ans stored at last-1 index
    ll n = v.size() - 1;
    ll temp = (v[n][0] - 1);
    return (temp + MOD) % MOD;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, len, num;
        cin >> n;
        ll a[n];

        f(i, n) cin >> a[i];

        vector<vector<ll>> rem(n + 1, vector<ll>(7));

        rem[0][0] = 1;

        f(i, n)
        {
            len = (ll)to_string(a[i]).size();
            num = 1;
            while (len--)
                num *= 10;
            // db2(a[i], num);
            update(rem, i, num, a[i]);
        }
        cout << ans(rem) << endl;
    }
    return 0;
}