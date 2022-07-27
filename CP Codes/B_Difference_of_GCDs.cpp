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
        ll n, l, r, flag = 1;
        cin >> n >> l >> r;
        vll v(n + 1, 0);
        string ans = "YES\n";
        l--;

        ff(i, 1, n + 1)
        {
            v[i] = (l + i) - (l % i);
            if (v[i] > r)
            {
                flag = 0;
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
        if (flag)
        {
            ff(i, 1, n + 1) cout << v[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}