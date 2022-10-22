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
        ll n;
        cin >> n;
        ll sum1 = 0, sum2 = 0, sum = 0;
        vll v(n);

        f(i, n)
        {
            cin >> v[i];
            sum += v[i];
        }
        f(i, n)
        {
            sum1 += v[i];
            if (sum1 <= 0)
                break;
        }
        fr(i, n - 1)
        {
            sum2 += v[i];
            if (sum2 <= 0)
                break;
        }
        if (min(sum1, sum2) > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}