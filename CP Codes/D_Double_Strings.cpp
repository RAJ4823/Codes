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
        ll n;
        cin >> n;

        vector<string> v(n);
        map<string, bool> m;
        vll ans(n, 0);
        f(i, n)
        {
            cin >> v[i];
            m[v[i]] = true;
        }

        f(i, n)
        {
            f(j, v[i].length())
            {
                string s1 = v[i].substr(0, j + 1);
                string s2 = v[i].substr(j + 1, v[i].length());
                if (m[s1] && m[s2])
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
        f(i, n) cout << ans[i];
        cout << endl;
    }
    return 0;
}