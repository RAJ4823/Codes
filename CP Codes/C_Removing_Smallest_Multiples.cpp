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
        ll n, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        bool m[n + 1];
        vll count(n + 1, 0);

        f(i, n)
        {
            if (s[i] == '0')
                m[i + 1] = true;
            else
                m[i + 1] = false;
        }

        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j += i)
            {
                if (!m[j])
                    break;
                count[j] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (m[i])
                ans += count[i];
        }
        cout << ans << endl;
    }
    return 0;
}