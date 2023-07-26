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
        int n;
        cin >> n; // Number of items

        vector<int> a(n), b(n);
        unordered_set<int> s;
        f(i, n) cin >> a[i];
        f(i, n) cin >> b[i];

        f(i, n)
        {
            if (a[i] == b[i])
            {
                if (a[i] != 0)
                    s.insert(2);
                continue;
            }
            if (a[i] == 0)
            {
                s.insert(0);
                continue;
            }
            if (b[i] == 0)
            {
                s.insert(1);
                continue;
            }

            int x = b[i] / __gcd(a[i], b[i]);
            int y = a[i] / __gcd(a[i], b[i]);

            if (x % 2 == y % 2)
                s.insert(2);
            else if (y % 2)
                s.insert(1);
            else
                s.insert(0);
        }

        if (s.size() <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}