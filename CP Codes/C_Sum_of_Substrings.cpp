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
        ll n, k, o = 0, sum = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        ll l = 0, r = 0;
        f(i, n)
        {
            if (s[i] == '1')
                o++;
        }
        f(i, n)
        {
            if (s[i] == '1')
            {
                l = i;
                break;
            }
        }
        fr(i, n - 1)
        {
            if (s[i] == '1')
            {
                r = (n - 1 - i);
                break;
            }
        }
        sum = o * 11;
        if (sum > 0)
        {
            if (r == 0)
                sum -= 10;
            if (l == 0)
                sum--;
        }
        if (k >= r && r != 0)
        {
            if (sum == 10)
                sum++;
            sum -= 10;
            k -= r;
        }
        if (k >= l && l != 0)
        {
            if(sum == 1)
                sum++;
            sum--;
        }
        cout << sum << endl;
    }

    return 0;
}