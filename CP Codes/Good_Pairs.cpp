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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];
        f(i, n) cin >> a[i];
        f(i, n) cin >> b[i];
        f(i, n)
        {
            ff(j, i + 1, n)
            {
                ll x = (a[i] ^ a[j]);
                ll y = (b[i] ^ b[j]);
                if (x == y)
                {
                    db2(a[i], a[j]);
                    db2(b[i], b[j]);
                    db2(x, y);
                }
            }
        }
        cout << endl;
    }
    return 0;
}