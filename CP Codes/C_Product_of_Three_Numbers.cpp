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

bool check(ll a, ll b, ll c)
{
    if (c == a || c == b)
        return false;
    ll mini = min(a, min(b, c));
    if (mini < 2)
        return false;
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll a = 0, b = 0, c = 0;
        for (ll i = 2; i * i <= n; i++)
        {
            if (a && b)
            {
                c = n / (a * b);
                break;
            }
            if (n % i == 0 && n / i > 1)
            {
                if (!a)
                    a = i;
                else if (n % (a * i) == 0 && n / (a * i) > 1)
                    b = i;
            }
        }
        if (check(a, b, c))
        {
            cout << "YES\n";
            cout << a << ' ' << b << ' ' << c << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}