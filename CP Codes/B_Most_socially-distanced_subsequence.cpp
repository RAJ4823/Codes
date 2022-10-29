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
        vll ans;
        f(i, n) cin >> v[i];

        //! MY APPROACH
        // int i = 0;
        // while (i < n - 1)
        // {
        //     if (v[i] < v[i + 1])
        //     {
        //         ans.push_back(v[i]);
        //         while (v[i] < v[i + 1] && i < n - 1)
        //         {
        //             i++;
        //         }
        //     }
        //     else
        //     {
        //         ans.push_back(v[i]);
        //         while (v[i] > v[i + 1] && i < n - 1)
        //         {
        //             i++;
        //         }
        //     }
        // }
        // ans.push_back(v[n - 1]);

        // Better approach
        f(i, n)
        {
            if (i == 0 || i == n - 1)
                ans.push_back(v[i]);
            else if ((v[i - 1] < v[i]) != (v[i] < v[i + 1]))
                ans.push_back(v[i]);
        }

        cout << ans.size() << endl;
        fauto(i, ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}