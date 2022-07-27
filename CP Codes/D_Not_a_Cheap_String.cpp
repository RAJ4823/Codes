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
        string s, str = "";
        cin >> s;
        ll n, sum = 0;
        cin >> n;
        vpll val;
        map<ll, bool> m;

        f(i, s.length())
        {
            val.push_back({(s[i] - 96), i});
        }
        sort(val.begin(), val.end());
        // f(i, val.size())
        // {
        //     char c = val[i].first + 97;
        //     int ix = val[i].second;
        //     db2(c, ix);
        // }
        f(i, s.length())
        {
            sum += val[i].first;
            // db2(i, sum);
            if (sum <= n)
                m[val[i].second] = true;
            else
                break;
        }
        f(i, s.size())
        {
            if (m[i])
                str += s[i];
        }
        cout << str << endl;
    }
    return 0;
}