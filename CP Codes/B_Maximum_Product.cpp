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
        int n;
        cin >> n;
        vll neg, pos;
        f(i, n)
        {
            ll x;
            cin >> x;
            if (x < 0)
                neg.push_back(x);
            else
                pos.push_back(x);
        }
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end(), greater<ll>());

        ll ans = LONG_LONG_MIN;
        ll N = neg.size(), P = pos.size();

        if (P == 0)
        {
            ans = 1;
            ff(i, N - 5, N) ans *= neg[i];
        }
        else
        {
            P = min(5ll, P);
            N = min(5ll, N);
            ff(i, 0, 6)
            {
                if (N >= i && (5 - i) <= P)
                {
                    ll mul1 = 1, mul2 = 1;
                    f(j, i) mul1 *= neg[j];
                    f(j, (5 - i)) mul2 *= pos[j];
                    ans = max(ans, (mul1 * mul2));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vll neg, pos;
//         f(i, n)
//         {
//             ll x;
//             cin >> x;
//             if (x < 0)
//                 neg.push_back(x);
//             else
//                 pos.push_back(x);
//         }
//         sort(neg.begin(), neg.end());
//         sort(pos.begin(), pos.end(), greater<ll>());

//         ll ans = LONG_LONG_MIN, temp = LONG_LONG_MIN;
//         ll ns = neg.size(), ps = pos.size(), ans2 = 1;
//         ps = min(5ll, ps);
//         ns = min(5ll, ns);
//         ll m = ns;
//         vll muln(ns + 1, 1), mulp(ps + 1, 1);

//         ff(i, 1, 6)
//         {
//             if (ns >= i)
//                 muln[i] = muln[i - 1] * neg[i - 1];
//             if (ps >= i)
//                 mulp[i] = mulp[i - 1] * pos[i - 1];
//         }
//         // fauto(i, muln) cout << i << ' ';
//         // cout << endl;
//         // fauto(i, mulp) cout << i << ' ';
//         // cout << endl;
//         if (ps == 0)
//         {
//             ans = 1;
//             int i = neg.size() - 1, k = 5;
//             while (k--)
//                 ans *= neg[i--];
//         }
//         else
//         {
//             ff(i, 0, 6)
//             {
//                 if (ns >= i && (5 - i) <= ps)
//                     temp = muln[i] * mulp[5 - i];
//                 ans = max(temp, ans);
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }