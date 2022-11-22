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
        string s;
        cin >> s;

        ll ans = 0;

        f(i, n)
        {
            ll count[10] = {0};
            ll dist = 0, maxi = 0;
            ff(j, i, n)
            {
                ll num = s[j] - '0';
                maxi = max(maxi, ++count[num]);

                if (count[num] == 1)
                    dist++;
                if (count[num] > 10)
                    break;
                if (maxi <= dist)
                    ans++;
            }
        }   
        cout << ans << endl;
    }
    return 0;
}