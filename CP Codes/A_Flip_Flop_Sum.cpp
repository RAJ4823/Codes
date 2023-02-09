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
        ll n, x, sum = 0;
        cin >> n;

        int neg = 0, cnt = 0;
        f(i, n)
        {
            cin >> x;
            sum += x;
            if (x < 0)
                neg++;
            else
            {
                cnt = max(neg, cnt);
                neg = 0;
            }
        }
        cnt = max(neg, cnt);
        if (cnt >= 2)
            cout << sum + 4 << endl;
        else if (cnt == 1)
            cout << sum << endl;
        else
            cout << sum - 4 << endl;
    }
    return 0;
}