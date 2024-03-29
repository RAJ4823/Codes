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
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin >> n;
        vll a(n), b(n);
        f(i,n) cin >> a[i];
        f(i,n) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());

        ll ways = 1;
        f(i,n) {
            ll diff = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            ways = (ways % MOD * (n - diff - i) % MOD) % MOD;
        }
        cout << ways << endl;
    }
    return 0;
}