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
const ll N = 2 * 1e5 + 10;
#define SIZE 1000001
#define MOD 1000000007LL

vll pw(N);
int main()
{
    ff(i, 1, N)
    {
        int count = 0;
        int temp = i;
        while (temp % 2 == 0)
        {
            count++;
            temp /= 2;
        }
        pw[i] = count;
    }
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt = 0, ans = 0;
        vll v(n);

        f(i, n)
        {
            ll temp;
            cin >> temp;
            while (temp % 2 == 0)
            {
                cnt++;
                temp /= 2;
            }
        }
        ll rem = max(0ll, n - cnt);
        f(i, n) v[i] = pw[i + 1];
        sort(v.rbegin(), v.rend());

        f(i, n)
        {
            if (rem <= 0)
                break;
            rem -= v[i];
            ans++;
        }
        if (rem > 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}