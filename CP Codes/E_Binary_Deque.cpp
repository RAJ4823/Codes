#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll get_ans(vll v, ll k)
{
    ll i = 0, j = 0, n = v.size();
    ll sum = 0, ans = -1;
    while (j < n)
    {
        sum += v[j];

        if (sum == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            sum -= v[i];
            sum -= v[j];
            i++;
        }
        else
        {
            j++;
        }
    }
    if (ans != -1)
        return (n - ans);
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll v(n);
        f(i, n) cin >> v[i];

        ll ans = get_ans(v, k);
        cout << ans << endl;
    }
    return 0;
}