#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n;
        mll m;

        ll dupli = 0, ans = 1;
        f(i, n)
        {
            cin >> x;
            m[x]++;
            if (m[x] == 2)
                dupli++;
        }
        ll dist = m.size();

        if (dist > 1)
        {
            if (dist % 2)
                dist++;
            else
                dupli++;
        
            ans = (dist / 2) + (dupli / 2);
        }
        cout << ans << endl;
    }
    return 0;
}