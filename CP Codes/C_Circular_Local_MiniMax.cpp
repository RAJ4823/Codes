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

bool check(vector<ll> &v)
{

    ff(i, 1, v.size() - 1)
    {
        if (v[i - 1] > v[i] && v[i + 1] > v[i])
            continue;
        else if (v[i - 1] < v[i] && v[i + 1] < v[i])
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll v;
        ll a[n];
        
        f(i, n) cin >> a[i];
        sort(a, a + n);
        ll j = (n / 2);

        f(i, j)
        {
            v.push_back(a[i]);
            v.push_back(a[i + j]);
        }
        if (n % 2)
            v.push_back(a[n - 1]);

        if (check(v))
        {
            cout << "YES\n";
            f(i, n) cout << v[i] << ' ';
            cout << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}