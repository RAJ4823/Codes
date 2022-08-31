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

// string solve(string s, int n)
// {
//     char ch = '1';
//     int count = 0;
//     bool flag = false;
//     if (s[0] != ch)
//         return "No";

//     for (int i = 1; i < n; i++)
//     {
//         if (s[i] == ch)
//         {
//             if (count == 0 || count > 2)
//                 return "No";
//             else
//                 count = 0;
//         }
//         else
//         {
//             count++;
//         }
//     }
//     if (count > 1)
//         return "No";
//     return "Yes";
// }

string solve(string str, int n)
{
    int f = 0, g = -1, d = 0;
    if (str[0] == '0' && n == 1)
        f = 1;
    else
    {
        f(i, n)
        {
            if (str[i] == '1' && g == -1)
                g = i;
            else if (str[i] == '1' && g != -1)
            {
                d = i - g;
                g = i;
                if (!(d > 1 && d < 4))
                {
                    f = 1;
                    break;
                }
            }
        }
    }
    if ((n - 1 - g) >= 2)
        f = 1;
    if (f)
        return "No";
    return "Yes";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = solve(s, n);
        cout << ans << endl;
    }
    return 0;
}
