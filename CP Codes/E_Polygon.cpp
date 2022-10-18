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
        ll m[n][n];
        f(i, n)
        {
            string s;
            cin >> s;
            f(j, n)
            {
                m[i][j] = (int)(s[j] - '0');
            }
        }
        bool flag = true;
        f(i, n - 1)
        {
            f(j, n - 1)
            {
                if (m[i][j] == 1)
                {
                    if (m[i][j + 1] == 0 && m[i + 1][j] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}