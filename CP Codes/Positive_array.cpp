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
#define MOD 1000000007LL

ll get_ans(mll &m)
{
    ll ans = 1, acc = 0;
    ll req, rem, diff;

    fauto(i, m)
    {
        req = i.second;
        rem = ans * (i.first) - acc;
        diff = req - rem;
        // db2(i.first, acc);

        if (req > rem)
        {
            ans += ((req - rem) / i.first);
            if (diff % i.first)
                ans++;
        }
        acc += i.second;
        // db2(req, rem);
        // db2(diff, acc);
        // db1(ans);
        // cout << endl;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n;
        mll m;

        f(i, n)
        {
            cin >> x;
            m[x]++;
        }
        cout << get_ans(m) << endl;
    }
    return 0;
}