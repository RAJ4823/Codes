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
#define db3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

// Optimal Approach (FULL AC)
void solve()
{
    ll n, x;
    cin >> n;
    vll arr(n + 1), sum(n + 1, 0), mul(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        mul[i] = mul[i - 1] + (n - i + 1) * arr[i];
    }

    vll stack;
    ll ans = 0;
    int j = n + 1;
    for (int i = n; i >= 1; i--)
    {
        //Will find the index 'j' for 'i' such that (prefix sum from index 'i' to 'j' < 0)
        while (!stack.empty() && sum[stack.back()] >= sum[i - 1])
            stack.pop_back();

        j = n;
        if (!stack.empty())
            j = stack.back() - 1;

        if (arr[i] >= 0)
            ans += (mul[j] - mul[i - 1]) - ((n - j) * (sum[j] - sum[i - 1]));
        stack.push_back(i);
    }
    cout << ans << endl;
}

// N^2 Approach (Partial Answer)
// void solve()
// {
//     ll n;
//     cin >> n;
//     vll v(n + 1), sum(n + 1, 0);
//     ll ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> v[i];
//         sum[i] = sum[i - 1] + v[i];
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j <= n; j++)
//         {
//             if (sum[j] - sum[i - 1] >= 0)
//                 ans += (sum[j] - sum[i - 1]);
//             else
//                 break;
//         }
//     }
//     cout << ans << endl;
// }

int main()
{
    int t;
    cin >> t;

    f(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}