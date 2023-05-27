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

string find(vll &v, ll n)
{
    ll eve = 0, odd = 0, firstOdd = 0;
    f(i, n)
    {
        if (v[i] % 2 == 0)
            eve++;
        else
            odd++;
        if (odd == 1 && firstOdd == 0)
            firstOdd = v[i];
    }
    if (eve == n || odd == n)
        return "YES";
    f(i, n)
    {
        if (v[i] % 2)
            continue;
        if(v[i] - firstOdd < 0)
            return "NO";
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);

        f(i, n) cin >> v[i];
        sort(v.begin(), v.end());
        cout << find(v, n) << endl;
    }
    return 0;
}