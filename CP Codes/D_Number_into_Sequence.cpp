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
        ll ans = n;
        mll m;
    
        while (n % 2 == 0)
        {
            m[2]++;
            n = n / 2;
        }
        for (ll i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                m[i]++;
                n = n / i;
            }
        }

        if (n > 2)
            m[n]++;

        ll maxi = 1, div = ans;
        fauto(i, m)
        {
            if (i.second > maxi)
            {
                maxi = i.second;
                div = i.first;
            }
        }

        if (maxi == 1)
        {
            cout << 1 << endl;
            cout << ans << endl;
        }
        else
        {
            cout << m[div] << endl;
            while (--m[div])
            {
                cout << div << ' ';
                ans /= div;
            }
            cout << ans << endl;
        }
    }
    return 0;
}