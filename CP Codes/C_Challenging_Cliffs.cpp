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

        f(i, n) cin >> v[i];
        sort(v.begin(), v.end());
        ll l, h, diff, mini = INT_MAX;
        f(i, n - 1)
        {
            diff = abs(v[i] - v[i + 1]);
            if (diff < mini)
            {
                mini = diff;
                l = i;
                h = i + 1;
            }
        }
        cout << v[l] << ' ';
        ff(i, h + 1, n) cout << v[i] << ' ';
        ff(i, 0, l) cout << v[i] << ' ';
        cout << v[h] << endl;
    }
    return 0;
}