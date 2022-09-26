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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int res, res2, rem, ans1, ans2, ans3;
    if (n % m)
        res2 = (n + m) / m;
    else
        res2 = n / m;

    res = n / m;
    rem = n - res * m;
    ans1 = res * b + rem * a;
    ans2 = n * a;
    ans3 = res2 * b;
    cout << min(ans1, min(ans2, ans3)) << endl;
    return 0;
}