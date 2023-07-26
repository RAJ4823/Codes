// ⭐ the_247 | Raj Patel ⭐
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define pqll priority_queue<ll>
#define umll unordered_map<ll, ll>
#define usll unordered_set<ll>
#define mll map<ll, ll>
#define sll set<ll>

#define fauto(i, a) for (auto &i : a)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)

#define all(x) (x).begin(), (x).end()
#define sortv(v) sort(all(v))
#define sortvd(v) sort(all(v), greater<>());
#define sortstr(str) sort(all(str))
#define sortstrd(str) sort(all(str), greater<char>())
#define tolowerstr(str) transform(all(str), str.begin(), ::tolower)
#define toupperstr(str) transform(all(str), str.begin(), ::toupper)
#define print_condition(x, s1, s2) cout << ((x) ? s1 : s2) << endl;
#define print_vector(v) fauto(x, v) cout << (x) << ' ';

#define db(x) cout << (#x) << " = " << x << "\n";
#define dbb(x, y) cout << (#x) << " = " << x << " , " << (#y) << " = " << y << "\n"

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007LL
#define MODD 998244353

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll v(n);
        mll cnt;
        ll left = -1, right = -1;

        f(i, 0, n) cin >> v[i];
        f(i, 0, n) cnt[v[i]]++;
        bool possible = true;

        if (v[0] == v[n - 1])
        {
            possible = (cnt[v[0]] >= k);
        }
        else
        {
            ll l = k, r = k;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == v[0])
                {
                    l--;
                }
                if (l == 0)
                {
                    left = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i] == v[n - 1])
                {
                    r--;
                }
                if (r == 0)
                {
                    right = i;
                    break;
                }
            }

            if (left == n - 1)
                possible = true;
            else if (left > right || l > 0 || r > 0)
                possible = false;
        }

        print_condition(possible, "YES", "NO");
    }
    return 0;
}