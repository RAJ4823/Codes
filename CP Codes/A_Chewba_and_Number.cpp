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
    ll n, dig;
    cin >> n;
    string num = "";
    while (n > 0)
    {
        dig = n % 10;
        num += (((dig >= 5) ? (9 - dig) : dig) + '0');
        n /= 10;
    }
    if (dig == 9)
    {
        num.pop_back();
        num += (dig + '0');
    }
    reverse(num.begin(), num.end());
    cout << num << endl;
    return 0;
}