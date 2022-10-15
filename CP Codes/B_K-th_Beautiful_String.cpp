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
        ll n, k;
        cin >> n >> k;
        string s = "";
        f(i, n) s += 'a';
        for (int i = n - 2; i >= 0; i--)
        {
            if (k <= (n - i - 1))
            {
                s[i] = 'b';
                s[n - k] = 'b';
                break;
            }
            k -= (n - i - 1);
        }
        cout << s << endl;
    }
    return 0;
}