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
        int n, o = 0, e = 1;
        cin >> n;
        int a = ++n / 2;
        if (n % 2)
        {
            o = 1;
            e = 0;
        }

        f(i, n - 1)
        {
            if (i % 2)
                a = a - (i * e) + (i * o);
            else
                a = a + (i * e) - (i * o);
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}