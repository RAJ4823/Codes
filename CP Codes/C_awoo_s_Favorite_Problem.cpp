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
        int n;
        string s, t;
        cin >> n;
        cin >> s;
        cin >> t;

        map<char, ll> ms, mt;
        bool ans = true;
        f(i, n)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }

        if (ms['a'] == mt['a'] && ms['c'] == mt['c'])
        {
            int j = 0;
            f(i, n)
            {
                if (s[i] == 'b')
                    continue;
                while (t[j] == 'b')
                    j++;
                if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j))
                {
                    ans = false;
                    break;
                }
                j++;
            }
        }
        else
            ans = false;

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}