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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll y, x;
        cin >> y >> x;
        
        if (y >= x)
        {
            if (y % 2)
            {
                cout << (y - 1) * (y - 1) + x << endl;
            }
            else
            {
                cout << y * y - x + 1 << endl;
            }
        }
        else
        {
            if (x % 2)
            {
                cout << x * x - y + 1 << endl;
            }
            else
            {
                cout << (x - 1) * (x - 1) + y << endl;
            }
        }
    }
    return 0;
}