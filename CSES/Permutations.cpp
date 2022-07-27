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
    ll n;
    cin >> n;
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    ff(i, 1, n + 1) if (i % 2 == 0)
    cout<< i << ' ';
    ff(i, 1, n + 1) if (i % 2)
    cout<< i << ' ';

    return 0;
}