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

vll dp(SIZE, -1);

int fun(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return 1e9;
    if (dp[n] != -1)
        return dp[n];

    int steps = 0, m = n, mini = 1e9;
    while (m > 0)
    {
        if (m % 10 != 0)
        {
            steps = 1 + fun(n - (m % 10));
            mini = min(steps, mini);
        }
        m /= 10;
    }
    return dp[n] = mini;
}
int main()
{
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}