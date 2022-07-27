#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define ft first
#define sd second
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
        ll n, count = 0, ans = 0;
        cin >> n;
        string s;
        cin >> s;

        ll j = n / 2;
        char ch = s[j];

        ff(i, j, n)
        {
            if (s[i] == ch)
                count++;
            else
                break;
        }
        ans = count * 2;
        
        if (n % 2)
            ans--;
        cout << ans << endl;
    }
    return 0;
}