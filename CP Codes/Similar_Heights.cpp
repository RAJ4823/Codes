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
#define fauto(i, a) for (auto i : a)

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, x, maxi = -1, dist = 0;
        ll count = 0;
        cin >> n;
        mll m;

        f(i, n)
        {
            cin >> x;
            m[x]++;
            maxi = max(x, maxi);
        }
        for (auto &i : m)
        {
            if (i.second == 1)
                dist++;
            else
                count = max(i.second, count);
        }

        if (m[maxi] == 1 && dist == 1)
        {
            if (count > 2)
                count = 1;
            cout << count << endl;
        }
        else
            cout << (++dist) / 2<< endl;
    }
    return 0;
}