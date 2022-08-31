#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x, y;
        cin >> x >> y;
        string s1 = x;
        string s2 = y;

        string ans = x;
        int w = lcm(x.length(), y.length());
        int z = x.length() * y.length();

        if (x.length() != y.length())
        {
            while (x.length() != z)
                x = x + s1;

            while (y.length() != z)
                y = y + s2;

            while (ans.length() != w)
                ans = ans + s1;

        }

        if (x == y)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}