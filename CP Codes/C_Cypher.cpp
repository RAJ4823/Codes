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
        ll n, count = 0;
        cin >> n;
        ll a[n];
        f(i, n) cin >> a[i];
        f(i, n)
        {
            ll x;
            string s;
            count = 0;

            cin >> x;
            cin >> s;

            f(i, x)
            {
                if (s[i] == 'U')
                    count--;
                else
                    count++;
            }

            a[i] = (a[i] + count) % 10;
            if (a[i] < 0)
                a[i] = 10 - abs(a[i]) % 10;
        }
        f(i, n)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}