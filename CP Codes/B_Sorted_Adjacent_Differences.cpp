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
        vll v(n), ans(n);
        f(i, n) cin >> v[i];
        sort(v.begin(), v.end());
        ll i = (n / 2) - 1, j = i + 1, k = 0;

        if (n % 2)
            ans[k++] = v[j++];
        while (k < n)
        {
            ans[k++] = v[j++];
            ans[k++] = v[i--];
        }
        fauto(x, ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}