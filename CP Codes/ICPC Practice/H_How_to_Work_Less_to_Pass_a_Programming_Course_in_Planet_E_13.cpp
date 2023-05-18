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
    ll n, g, sum = 0;
    cin >> n >> g;
    vpll v(n);
    f(i, n)
    {
        ll x;
        cin >> x;
        v[i] = {x, i};
        sum += x;
    }
    sort(v.begin(), v.end());
    ll tempSum = 0, avg = 0;
    ll mini = n;
    for (int i = n - 1; i >= 0; i--)
    {
        tempSum += v[i].first;
        if ((tempSum / sum) * 100 >= g)
        {
            mini = (n - i + 1);
            break;
        }
    }
    cout << mini << endl;
    return 0;
}