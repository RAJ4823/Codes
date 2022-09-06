#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
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
    ll n, k, count = 0, sum = 0;
    string s;
    map<char, ll> dp;

    cin >> n >> k;
    cin >> s;
    f(i, k)
    {
        char c;
        cin >> c;
        dp[c] = true;
    }
    f(i, n)
    {
        if (dp[s[i]])
            count++;
        else
        {
            sum += (count * (count + 1)) / 2;
            count = 0;
        }
    }
    sum += (count * (count + 1)) / 2;
    cout << sum << endl;
    return 0;
}