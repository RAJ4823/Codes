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
        int n;
        cin >> n;
        string t, s = "";
        cin >> t;
        int i = n - 1, num;
        while (i >= 0)
        {
            if (t[i] == '0')
            {
                int dec = (int)(t[i - 2] - 48);
                num = (int)(t[i - 1] - 48) + dec * 10;
                i -= 3;
            }
            else
            {
                num = (int)(t[i] - 48);
                i--;
            }
            s.push_back((char)(num + 96));
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}