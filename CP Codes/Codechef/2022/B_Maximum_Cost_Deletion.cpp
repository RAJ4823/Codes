#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define yn(x) (x) ? cout << "YES\n" : cout << "NO\n";
#define ynif(x, y) (x == y) ? cout << "YES\n" : cout << "NO\n";
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll ans(string s, char ch, ll a, ll b)
{
    ll sum = 0, count1 = 0, count2 = 0;
    f(i, s.length())
    {
        if (ch != s[i])
            count2++;
    }
    f(i, s.length())
    {
        if (ch == s[i])
        {
            count1++;
        }
        else if (count1 > 0)
        {
            sum += max((a + b) * count1, count1 * a + b);
            count1 = 0;
            // db2(i, sum);
        }
    }
    if (count1 > 0)
        sum += max((a + b) * count1, count1 * a + b);
    // db2(count1, sum);
    if (count2 > 0)
        sum += max((a + b) * count2, count2 * a + b);
    // db2(count2, sum);
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        ll sum1 = ans(s, '0', a, b);
        ll sum2 = ans(s, '1', a, b);
        cout << max(sum1, sum2) << endl;
    }
    return 0;
}