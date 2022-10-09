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

bool isSort(vll &a)
{
    f(i, a.size() - 1)
    {
        if (a[i + 1] < a[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vll s(k), a(k - 1);
        f(i, k) cin >> s[i];

        string ans = "YES\n";
        if (k > 1)
        {
            f(i, k - 1) a[i] = s[i + 1] - s[i];
            if (!isSort(a))
                ans = "NO\n";
            if (s[0] > a[0] * (n - k + 1))
                ans = "NO\n";
        }
        cout << ans;
    }
    return 0;
}