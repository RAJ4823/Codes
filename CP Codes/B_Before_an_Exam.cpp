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
    int n, sum;
    cin >> n >> sum;
    vll mx(n), mn(n);
    int x = 0, y = 0;
    f(i, n)
    {
        cin >> mn[i] >> mx[i];
        x += mx[i];
        y += mn[i];
    }
    if (sum > x || sum < y)
    {
        cout << "NO\n";
        return 0;
    }
    int need = x - sum;
    f(i, n)
    {
        if (mx[i] - mn[i] >= need)
        {
            mx[i] -= need;
            break;
        }
        else if (mx[i] - mn[i] < need)
        {
            need -= mx[i] - mn[i];
            mx[i] = mn[i];
        }
    }
    cout << "YES\n";
    f(i, n) cout << mx[i] << ' ';
}