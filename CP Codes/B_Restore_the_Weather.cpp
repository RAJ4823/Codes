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
        ll n,k;
        cin >> n >> k;

        vpll a(n), b(n);
        vll ans(n);
        f(i,n) {
            ll x;
            cin >> x;
            a[i] = {x, i};
        }
        f(i, n) {
            ll x;
            cin >> x;
            b[i] = {x, i};
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        f(i,n) {
            ans[a[i].second] =  b[i].first;
        }
        f(i,n) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}