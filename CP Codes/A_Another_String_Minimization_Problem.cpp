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
        ll n, m;
        cin >> n >> m;
        vll v(n);
        vector<char> pos(m, 'B');
        f(i, n) cin >> v[i];
        sort(v.begin(), v.end());
        f(i, n)
        {
            ll x = v[i] - 1;
            ll y = (m - v[i]);
            if (pos[x] == 'B' && pos[y] == 'B')
            {
                if (x < y)
                    pos[x] = 'A';
                else
                    pos[y] = 'A';
            }
            else if(pos[x] == 'B')
                pos[x] = 'A';
            else
                pos[y] = 'A';
        }
        f(i, m) cout << pos[i];
        cout << endl;
    }
    return 0;
}