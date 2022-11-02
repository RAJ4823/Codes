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
    ll n, m;
    cin >> n >> m;

    if (n == 1 && m < 10)
    {
        cout << m << ' ' << m << endl;
    }
    else if (n * 9 < m || m == 0)
    {
        cout << "-1 -1\n";
    }
    else
    {
        vll mini(n, 0), maxi(n, 0);
        mini[0] = 1;
        maxi[0] = min(9ll, m);
        ll sum = m - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (sum > 0)
            {
                mini[i] += min(9ll, sum);
                sum -= min(9ll, sum);
            }
        }
        sum = m - maxi[0];
        for (int i = 1; i < n; i++)
        {
            if (sum > 0)
            {
                maxi[i] += min(9ll, sum);
                sum -= min(9ll, sum);
            }
        }

        string a = "", b = "";
        fauto(i, mini) a += (char)(i + '0');
        fauto(i, maxi) b += (char)(i + '0');
        cout << a << ' ' << b << endl;
    }
    return 0;
}