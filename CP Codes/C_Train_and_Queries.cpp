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
        string str;
        getline(cin, str);

        ll n, k;
        cin >> n >> k;
        vll v(n);
        mll f, s, p;
        f(i, n)
        {
            cin >> v[i];
            if (p[v[i]] == 0)
                f[v[i]] = i;
            else
                s[v[i]] = i;
            p[v[i]] = 1;
        }

        while (k--)
        {
            int x, y;
            cin >> x >> y;
            if (p[x] && p[y])
            {
                if (f[x] <= f[y])
                    cout << "YES\n";
                else if (f[x] <= s[y])
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}