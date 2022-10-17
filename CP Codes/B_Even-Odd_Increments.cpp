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
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, q, y;
        cin >> n >> q;
        ll eve = 0, odd = 0, sum = 0;
        f(i, n)
        {
            cin >> y;
            if (y % 2 == 0)
                eve++;
            else
                odd++;
            sum += y;
        }

        while (q--)
        {
            int type, val;
            cin >> type >> val;
            if (type == 0)
            {
                sum += val * eve;
                if (val % 2)
                {
                    odd += eve;
                    eve = 0;
                }
            }
            else
            {
                sum += val * odd;
                if (val % 2)
                {
                    eve += odd;
                    odd = 0;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}