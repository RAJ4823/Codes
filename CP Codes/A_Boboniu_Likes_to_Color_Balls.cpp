#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll by2(ll n)
{
    if (n % 2)
        return 0;
    else
        return 1;
}

bool check(ll a, ll b, ll c, ll d)
{
    if (a < 0 || b < 0 || c < 0)
        return false;
    int count = 0;
    count += by2(a);
    count += by2(b);
    count += by2(c);
    count += by2(d);
    if (count >= 3)
        return true;
    else
        return false;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        bool ans1, ans2;
        ans1 = check(a, b, c, d);
        ans2 = check(a - 1, b - 1, c - 1, d + 3);

        if (ans1 || ans2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}