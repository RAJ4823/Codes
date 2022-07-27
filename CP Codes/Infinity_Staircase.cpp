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
        ll n, ans;
        cin >> n;
        n--;
        ll x, y = 0, z;
        z = n / 3;
        if (z > 1)
        {
            x = z / 2;
            y = (z - x);
            ans = min(x,y)*2 + max(x,y);
        }
        else
        {
            ans = 1;
        }

        if (n % 3 != 0 && n > 2)
        {
            ans++;
        }
        if (n == 0)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}