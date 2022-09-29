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

pll getMinMax(ll n)
{
    ll mini = 9, maxi = 0;
    while (n > 0)
    {
        mini = min(mini, (n % 10));
        maxi = max(maxi, (n % 10));
        n /= 10;
    }
    return {mini, maxi};
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        f(i, k - 1)
        {
            auto p = getMinMax(n);
            if (p.first == 0)
                break;
            n += (p.first * p.second);
        }
        cout << n << endl;
    }
    return 0;
}