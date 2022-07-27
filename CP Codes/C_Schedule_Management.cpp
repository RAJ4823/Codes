#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
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
        ll n, m, x;
        cin >> n >> m;

        vll v(m), a;
        mll cnt;
        ll rem = 0, ans = -1, same = 0;

        f(i, m)
        {
            cin >> v[i];
            if (cnt[v[i]] == 0)
                a.push_back(v[i]);
            cnt[v[i]]++;
        }
        rem = n - a.size();
        f(i, a.size())
        {
            if (cnt[a[i]] > 3)
            {
                if (rem > 0)
                {
                    rem--;
                    same = cnt[a[i]] / 3;
                    same = cnt[a[i]] - same;
                    ans = max(ans, same);
                }
                else
                {
                    same = cnt[a[i]];
                    ans = max(ans, same);
                }
            }
            else
            {
                ans = max(ans, cnt[a[i]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}