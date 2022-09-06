#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
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

int solve(int f, int l, vector<int> &v)
{
    if (l <= f)
        return 0;

    if (max(v[f], v[l]) == f)
        return v[f] + max(solve(f + 2, l, v), solve(f + 1, l - 1, v));
    return v[l] + max(solve(f, l - 2, v), solve(f + 1, l - 1, v));
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    f(i, n) cin >> v[i];

    if (n == 1)
        cout << v[0];
    else if (n == 2)
        cout << max(v[1], v[2]);
    else
    {
        int first = v[0], last = v[n - 1];
        if (max(v[1], v[n - 1]) == v[1])
            first += solve(2, n - 1, v);
        else
            first += solve(1, n - 2, v);

        if (max(v[0], v[n - 2]) == v[0])
            last += solve(2, n - 2, v);
        else
            last += solve(1, n - 3, v);
        cout << max(first, last);
    }
    return 0;
}