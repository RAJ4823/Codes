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
        ll n, x;
        cin >> n >> x;
        ll a[2*n];
        string ans = "YES\n";

        f(i, 2 * n)
        {
            cin >> a[i];
        }
        sort(a, a + 2*n);
        f(i, n)
        {
            // db2(a[n + i], a[i]);
            if (a[n + i] - a[i] >= x)
            {
                continue;
            }
            else
            {
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
    }
    return 0;
}