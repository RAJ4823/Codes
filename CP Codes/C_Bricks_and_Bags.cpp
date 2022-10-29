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

        vll v(n);
        vpll ans(3);
        ll mini = INT_MAX, maxi = INT_MIN;
        ll mini2 = INT_MAX, maxi2 = INT_MIN;
        ll i_min = 0, i_max = 0;

        f(i, n) cin >> v[i];
        sort(v.begin(), v.end());
        ll sum1 = 0, sum2 = 0;

        f(i, n - 2)
        {
            sum1 = max(sum1, abs(v[i] - v[i + 1]) + abs(v[i] - v[n - 1]));
        }
        ff(i, 1, n - 1)
        {
            sum2 = max(sum2, abs(v[i] - v[i + 1]) + abs(v[i + 1] - v[0]));
        }
        cout << max(sum1, sum2) << endl;
    }
    return 0;
}