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
        ll n, x, sum = 0;
        cin >> n >> x;
        vll v(n);
        bool flag = true;
        f(i, n)
        {
            cin >> v[i];
            flag &= (v[i] % x == 0);
            sum += v[i];
        }
        if (flag)
            cout << -1 << endl;
        else if (sum % x)
            cout << n << endl;
        else
        {
            ll ans1, ans2;
            f(i, n)
            {
                if (v[i] % x)
                {
                    ans1 = (n - i - 1);
                    break;
                }
            }
            fr(i, n - 1)
            {
                if (v[i] % x)
                {
                    ans2 = i;
                    break;
                }
            }
            cout << max(ans1, ans2) << endl;
        }
    }
    return 0;
}