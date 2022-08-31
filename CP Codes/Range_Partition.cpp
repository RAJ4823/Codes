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
    ll t, caseNo = 1;
    cin >> t;

    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll sum = (n * (n + 1)) / 2;

        if (((x * sum) % (x + y)) == 0)
        {
            ll sum1 = (x * sum) / (x + y);
            // db2(sum, sum1);
            vll v;
            while (sum1 >= 0 && n > 0)
            {
                if (sum1 >= n)
                {
                    v.push_back(n);
                    sum1 -= n;
                }
                n--;
            }
            cout << "Case #" << caseNo << ": ";
            cout << "POSSIBLE" << endl;
            cout << v.size() << endl;
            fauto(i, v) cout << i << ' ';
            cout << endl;
        }
        else
        {
            cout << "Case #" << caseNo << ": ";
            cout << "IMPOSSIBLE";
            cout << endl;
        }
        caseNo++;
    }
    return 0;
}