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

void get_ans(vll &v)
{
    ff(i, 0, v.size())
    {
        ff(j, i + 1, v.size())
        {
            ff(k, j + 1, v.size())
            {
                if ((v[i] + v[j] + v[k]) % 10 == 3)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll a[n];
        mll m;
        vll v;
        f(i, n)
        {
            cin >> a[i];
            m[a[i] % 10]++;
        }
        m[1] = min(m[1], 3LL);
        ff(i, 0, 10)
        {
            if (i != 1)
                m[i] = min(m[i], 2LL);
            while (m[i]--)
                v.push_back(i);
        }
        get_ans(v);
    }
    return 0;
}