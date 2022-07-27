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
#define db1(i) cout << #i << " = " << (i) << "\n";
#define db2(i, value) cout << #i << " = " << (i) << " " << #value << " = " << (value) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    ll n, t, sum = 0;
    cin >> n >> t;
    vll m(n);

    f(i, n)
    {
        cin >> m[i];
        sum += m[i];
    }

    ll s, sval, f, fval;

    while (t--)
    {
        int i;
        cin >> i;

        if (i == 1)
        {
            ll i, value;
            cin >> i >> value;
            i--;
            f = i;
            fval = value;
          
            cout << sum << endl;
        }
        else
        {
            ll value;
            cin >> value;
            
            sum = n * value;
            cout << sum << endl;
        }
    }
    return 0;
}