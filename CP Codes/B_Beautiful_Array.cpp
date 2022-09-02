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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        ll x = b * k;
        ll diff = s - x;
        vll ans(n);
        if (diff >= k)
        {
            x += (k - 1);
            diff -= (k - 1);
        }
        if (diff < 0)
        {
            cout << -1 << endl;
        }
        else
        {
            ans[0] = x;
            ff(i, 1, n)
            {
                if (diff > k - 1)
                {
                    ans[i] = (k - 1);
                    diff -= k - 1;
                }
                else if (diff >= 0)
                {
                    ans[i] = diff;
                    diff = 0;
                }
            }
            if (diff > 0)
                cout << -1;
            else
                fauto(i, ans) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}