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
        string s;
        cin >> s;
        ll n = s.length();
        ll occ[10] = {0}, index[10] = {0};

        f(i, n)
        {
            ll num = (int)(s[i] - '0');
            occ[num]++;
            index[num] = (i + 1);
        }

        ll prev = occ[0], curr = occ[0];
        bool flag = false;
        string ans;
        f(num, 10)
        {
            char c = '0' + num;
            if (num > 0)
                curr = prev + occ[num];

            while (occ[num]--)
            {
                if (flag)
                    ans += c;
                else
                    ans += (num == 9) ? (c) : (c + 1);
            }

            if (index[num] == curr)
                flag = true;
            prev = curr;
        }
        cout << ans << endl;
    }
    return 0;
}