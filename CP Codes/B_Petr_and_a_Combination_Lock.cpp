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

bool find(int i, int tar, int k, vll &arr, vvll &dp)
{
    // tar %= 360;
    if (i == 0)
        return ((tar + arr[i]) % 360 == 0);

    if (dp[i][tar + k] != -1)
        return dp[i][tar + k];

    bool add = find(i - 1, (tar + arr[i]), k, arr, dp);
    bool del = find(i - 1, (tar - arr[i]), k, arr, dp);
    return dp[i][tar + k] = (add || del);
}
int main()
{
    int n;
    cin >> n;

    vll arr(n);
    int totalSum = 0;
    f(i, n)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }
    if (totalSum % 2)
        cout << "NO\n";
    else
    {
        int m = 2 * totalSum + 1;
        vvll dp(n, vll(m, -1));
        if (find(n - 1, 0, totalSum, arr, dp))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}