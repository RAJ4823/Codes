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
        int x1, y1, x2, y2, x3, y3;

        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        set<int> x, y;
        x.insert(x1);
        x.insert(x2);
        x.insert(x3);

        y.insert(y1);
        y.insert(y2);
        y.insert(y3);

        if(x.size() == 3 || y.size() == 3)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}