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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll x, y, z;
        cin >> x >> y;
        bool flag = false;
        ll n = 1000, i, j;
        vll v;
        vector<bool> prime(n + 1, true);
        for (i = 2; i * i <= n; i++)
            if (prime[i])
                for (j = i * i; j <= n; j += i)
                    prime[j] = false;

        for (i = 2; i <= n; i++)
            if (prime[i])
                v.push_back(i);

        f(i, v.size())
        {
            f(j, v.size())
            {
                f(k, v.size())
                {
                    if ((v[i] ^ v[j]) == x && (v[j] ^ v[k]) == y)
                    {
                        z = (k ^ i);
                        if (x % 2 || y % 2 || z % 2)
                        {
                            cout << v[i] << ' ' << v[j] << ' ' << v[k] << endl;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}