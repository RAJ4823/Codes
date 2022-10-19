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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vll p;
        p.push_back(-1e9);
        f(i, n)
        {
            if (s[i] == '1')
                p.push_back(i);
        }
        p.push_back(1e9);
        ll j = 0, count = 0;
        f(i, n)
        {
            if (s[i] == '0')
            {
                int left = p[j] + k + 1;
                int right = p[j + 1] - k - 1;
                // db2(i, p[j]);
                // db2(left, right);
                if (i >= left && i <= right)
                {
                    count++;
                    p[j] = i;
                }
            }
            else
            {
                j++;
            }
        }
        cout << count << endl;
    }

    return 0;
}