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

bool check(vll &v1, vll &v2)
{
    f(i, v1.size() - 1)
    {
        if (v1[i] > v1[i + 1])
            return false;
        if (v2[i] > v2[i + 1])
            return false;
    }
    return true;
}
void swap(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll v1(n), v2(n);
        vpll ans;
        bool flag = true;
        f(i, n) cin >> v1[i];
        f(i, n) cin >> v2[i];
        f(i, n)
        {
            ff(j, i + 1, n)
            {
                if (v1[i] <= v1[j] && v2[i] <= v2[j])
                {
                    continue;
                }
                else
                {
                    ans.push_back({i, j});
                    swap(&v2[i], &v2[j]);
                    swap(&v1[i], &v1[j]);
                }
            }
        }

        if (check(v1, v2))
        {
            cout << ans.size() << endl;
            for (auto i : ans)
                cout << ++i.first << ' ' << ++i.second << endl;
            if (ans.size() != 0)
                cout << endl;
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}