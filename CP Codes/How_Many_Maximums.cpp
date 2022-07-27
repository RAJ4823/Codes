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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll count = 0;

        if (n == 2)
        {
            count = 1;
        }
        else
        {
            if (s[0] == '1')
                count++;
            for (ll i = 1; i < n - 1; i++)
            {
                if (s[i] == '1' && s[i - 1] == '0')
                    count++;
            }
            if (s[n - 2] == '0')
                count++;
        }
        cout << count << endl;
    }

    return 0;
}