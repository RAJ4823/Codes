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

//! True but giving RunTimeError because of recursion stack space
//* USE 1D DP for correct ans.
//! Memory can also affect time

// ll fun(int n, int currPrice, vll &prices, vll &pages, vvll &dp)
// {
//     if (n == 0)
//     {
//         if (currPrice >= prices[0])
//             return pages[0];
//         return 0;
//     }
//     if (dp[n][currPrice] != -1)
//         return dp[n][currPrice];
//     ll notpick = fun(n - 1, currPrice, prices, pages, dp);
//     ll pick = 0;
//     if (currPrice >= prices[n])
//         pick = pages[n] + fun(n - 1, currPrice - prices[n], prices, pages, dp);
//     return dp[n][currPrice] = max(pick, notpick);
// }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vll pages(n), prices(n);

    f(i, n) cin >> prices[i];
    f(i, n) cin >> pages[i];
    // vvll dp(n + 1, vll(x + 1, -1));
    // cout << fun(n - 1, x, prices, pages, dp);

    // 2 vector solution - space optimization
    vll dp(x + 1, 0), temp(x + 1, 0);
    for (int i = prices[0]; i <= x; i++)
        dp[i] = pages[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            ll pick = 0;
            if (j >= prices[i])
                pick = pages[i] + dp[j - prices[i]];
            temp[j] = max(pick, dp[j]);
        }
        dp = temp;
    }
    cout << dp[x];

    // Single vector sollution..
    // Extreme space optimization

    // vll dp(x + 1, 0);
    // for (int i = prices[0]; i <= x; i++)
    //     dp[i] = pages[0];

    // for (int i = 1; i < n; i++)
    // {
    //     // Moving right to left for filling values that only tequires left sides
    //     for (int price = x; price >= 0; price--)
    //     {
    //         ll pick = 0;
    //         if (price >= prices[i])
    //             pick = pages[i] + dp[price - prices[i]];
    //         dp[price] = max(dp[price], pick);
    //     }
    // }
    // cout << dp[x];
    return 0;
}
