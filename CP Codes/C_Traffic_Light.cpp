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
        char find;
        cin >> n >> find;
        string s;
        cin >> s;
        vector<int> a, b;
        f(i, n)
        {
            if (s[i] == find)
                a.push_back(i + 1);
            if (s[i] == 'g')
                b.push_back(i + 1);
        }
        int steps = 0, ans = 0;
        if (find != 'g')
        {
            for (int i = 0; i < a.size(); i++)
            {
                steps = n;
                for (int j = 0; j < b.size(); j++)
                {
                    if (b[j] < a[i])
                        steps = min(steps, n - a[i] + b[j]);
                    else
                        steps = min(steps, b[j] - a[i]);
                }
                ans = max(ans, steps);
            }
        }
        cout << ans << endl;
    }
    return 0;
}