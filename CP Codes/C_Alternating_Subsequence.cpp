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

//! O(1) space complexity solution
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, curr = 0, prev = 0, maxi = -1e9, ans = 0;
        cin >> n;
        f(i, n)
        {
            cin >> curr;
            if (i > 0 && (prev > 0) != (curr > 0))
            {
                ans += maxi;
                maxi = -1e9;
            }
            maxi = max(maxi, curr);
            prev = curr;
        }
        cout << ans + maxi << endl;
    }
    return 0;
}