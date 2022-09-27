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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x1 - x2), dy = abs(y1 - y2);

    if (x1 != x2 && y1 != y2 && dx != dy)
        cout << -1 << endl;
    else if (x1 == x2)
        cout << x1 + dy << " " << y1 << " " << x2 + dy << " " << y2 << endl;
    else if (y1 == y2)
        cout << x1 << " " << y1 + dx << " " << x2 << " " << y2 + dx << endl;
    else
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    return 0;
}