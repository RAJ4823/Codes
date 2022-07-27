#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
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
        string s, ans = "YES\n";
        cin >> s;
        ll c1 = 0, c2 = 0, n = s.length();
        bool arr[n][2] = {false};
        arr[0][0] = true;
        arr[n - 1][1] = true;
        f(i, n)
        {
            if (s[i] == '(')
            {
                arr[i][0] = true;
                c1 = 0;
            }
            else if (s[i] == ')')
            {
                arr[i][1] = true;
                c1 = 0;
            }
            else
            {
                c1++;
            }
            c2 = max(c2, c1);
        }
        c2 = max(c2, c1);
        ff(i, 1, n - 1)
        {
            if (s[i] != '?')
                continue;
            if (!arr[i][0])
            {
                if (s[i - 1] == '?')
                    arr[i][0] = true;
                else if (arr[n - i][1] == true && (i != (n - i)))
                    arr[i][0] = true;
            }
            if (!arr[i][1])
            {
                if (s[i + 1] == '?')
                    arr[i][1] = true;
                else if (arr[n - i - 2][0] == true && (i != (n - i - 2)))
                    arr[i][1] = true;
            }
        }
        f(i, n)
        {
            cout << i << " = ";
            f(j, 2)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }

        ff(i, 0, n)
        {
            if (arr[i][0] && arr[i][1])
            {
                // db1(i);
                ans = "NO\n";
                break;
            }
        }

        cout << ans;
    }
    return 0;
}