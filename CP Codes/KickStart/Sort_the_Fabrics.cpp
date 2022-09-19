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

void solve()
{
    int n;
    cin >> n;
    vector<pair<string, int>> v1(n);
    vector<pair<int, int>> v2(n);
    string s;
    int d, u, count = 0;

    f(i, n)
    {
        cin >> s >> d >> u;
        v1[i] = {s, u};
        v2[i] = {d, u};
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    f(i, n)
    {
        if (v1[i].second == v2[i].second)
            count++;
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;

    f(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}