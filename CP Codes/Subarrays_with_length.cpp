#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mll map<ll, ll>

ll getCount(ll n, ll x, ll i)
{
    ll I = min((i + 1), (n - i));
    ll V = min(abs(n - x + 1), x);
    return min(I, V);
}

ll getDiff(ll n, ll j, ll i)
{
    return (min(i, n) - min(j, n));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, ans = 0, cnt = 0;
        cin >> n;
        mll count, index;

        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            cnt = getCount(n, x, i);
            if (i < index[x])
                cnt = getDiff(n, index[x], i + x);
            ans += cnt;
            index[x] = i + x;
        }
        cout << ans << endl;
    }
    return 0;
}
// #define vi vector<ll>
// #define mi map<ll, ll>
// #define pb push_back
// #define mp make_pair
// const ll int MX = 1e9 + 7;
// #define MOD 1000007
// #define ee endl
// using namespace std;
// ll int arr2[MOD] = {0};

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll int n;
//         cin >> n;
//         vi v;
//         mi m;
//         for (ll int i = 0; i < n; i++)
//         {
//             ll int x;
//             cin >> x;
//             v.pb(x);
//         }
//         ll int back = 0, forth = 0, ans = 0, total;
//         for (ll int i = 0; i < n; i++)
//         {
//             if (m[v[i]] != 0)
//             {
//                 back = i - m[v[i]] ;
//                 m[v[i]] = i+1;
//             }
//             else
//             {
//                 back = i;
//                 m[v[i]] = i+1;
//             }
//             forth = n - i - 1;
//             // cout<<back<<" "<<forth<<ee;
//             if (back >= v[i] - 1 && forth >= v[i] - 1)
//             {
//                 ans += v[i];
//             }
//             else if (back >= v[i] - 1 && forth < v[i] - 1)
//             {
//                 ans += forth + 1;
//             }
//             else if (back < v[i] - 1 && forth >= v[i] - 1)
//             {
//                 ans += back + 1;
//             }
//             else
//             {
//                 total = back + forth;
//                 if (total + 1 < v[i])
//                 {
//                     ans += 0;
//                 }
//                 else if (total + 1 == v[i])
//                 {
//                     ans += 1;
//                 }
//                 else
//                 {
//                     ans += v[i] - total + 2;
//                 }
//             }
//         }
//         cout << ans << ee;
//     }
//     return 0;
// }