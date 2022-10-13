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

string solve(map<char, int> m[])
{
    return "YES";
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<char, int> m[3];
        while (n--)
        {
            string str, ans = "YES";
            int d, k, flag = 0;
            cin >> d >> k >> str;

            fauto(i, str) m[d][i] += k;

            for (char i = 'a'; i <= 'z'; i++)
            {
                for (char j = i + 1; j <= 'z'; j++)
                {
                    if (m[1][i] && m[2][j])
                    {
                        cout << ans << endl;
                        goto outer;
                    }
                }
            }

            for (char i = 'a'; i <= 'z'; i++)
            {
                if (m[1][i])
                {
                    for (int j = 'a'; j < i; j++)
                        if (m[2][j])
                            ans = "NO";
                    flag++;
                }
            }

            if (flag <= 1)
            {
                for (char i = 'a'; i <= 'z'; ++i)
                    if (m[2][i] <= m[1][i] && m[1][i])
                        ans = "NO";
            }
            else
            {
                ans = "NO";
            }

            cout << ans << endl;
        outer:;
        }
    }
    return 0;
}