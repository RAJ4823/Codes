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

    f(c, t)
    {
        ll n;
        cin >> n;

        string s, m;
        cin >> s >> m;

        int j = 0, k = n - 1, i = n - 1;
        bool flag = true;
        int count = 0;
        while (j <= k && i >= 0)
        {
            if (m[j] == s[i])
            {
                j++;
            }
            else if (m[k] == s[i])
            {
                k--;
            }
            else
            {
                flag = false;
                break;
            }
            i--;
        }

        cout << "Case " << c+1 << ": ";
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}