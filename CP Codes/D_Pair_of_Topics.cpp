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
    ll n;
    cin >> n;
    vll a(n), b(n), diff(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];
    f(i, n) diff[i] = a[i] - b[i];
    sort(diff.begin(), diff.end());

    ll count = 0;
    f(i, n)
    {
        if (diff[i] <= 0)
            continue;
        ll index = lower_bound(diff.begin(), diff.end(), 1 - diff[i]) - diff.begin();
        count += (i - index);
        // db2(diff[i], index);
    }
    cout << count << endl;
    return 0;
}