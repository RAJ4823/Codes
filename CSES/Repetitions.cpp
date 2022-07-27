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
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int count = 0, ans = -1;
    f(i, n - 1)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            ans = max(ans, count+1);
            count = 0;
        }
    }
    ans = max(ans, count+1);
    cout << ans << endl;
    return 0;
}