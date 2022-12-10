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
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        ll count0 = 0, count1 = 0;
        ll pre0 = 0, pre1 = 0;
        f(i,n)
        {
            count0 += (s[i] == '0');
            count1 += (s[i] == '1');
        }

        ll ans = min(count0, count1);
        f(i,n)
        {
            pre0 += (s[i] == '0');
            count0 -= (s[i] == '0');
            ans = min(ans, pre1 + count0);

            pre1 += (s[i] == '1');
            count1 -= (s[i] == '1');
            ans = min(ans, pre0 + count1);
        }
        cout << ans << endl;
    }
    return 0;
}