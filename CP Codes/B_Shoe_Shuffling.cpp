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
        ll n;
        cin >> n;
        ll a[n];
        mll m, in;
        bool flag = true;

        f(i, n)
        {
            cin >> a[i];
            m[a[i]]++;
            in[a[i]] = i+1;
        }
        for (auto i : m)
        {
            if (i.second < 2)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << "-1\n";
        else
        {
            ll y = 0, z = 0, j = 0;
            for (auto i : m)
            {
                cout << in[i.first] << ' ';
                j = in[i.first] - i.second + 1;
                while (j != in[i.first])
                {
                    cout << j++ << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}