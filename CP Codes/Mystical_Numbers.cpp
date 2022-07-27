#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll n, temp;
        scanf("%lld", &n);

        map<ll, ll> m;
        map<ll, map<ll, ll>> m2;

        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &temp);
            m[log2(temp)]++;
            m2[i] = m;
        }

        ll q;
        cin >> q;
        while (q--)
        {
            ll l, r, x, length, ans;
            scanf("%lld %lld %lld", &l, &r, &x);
            length = (r - l + 1);

            if (l == 1)
            {
                r--;
                ans = length - m2[r][log2(x)];
            }
            else
            {
                r--;
                l -= 2;
                ans = length - m2[r][log2(x)] + m2[l][log2(x)];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}