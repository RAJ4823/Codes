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
        int n;
        cin >> n;
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        bool flag = true;
        if (s[i] != 'm') flag = false;

        while (i++ < n && (s[i] == 'm')){}
        if (i == n || (s[i] != 'e'))flag = false;

        while (i++ < n && (s[i] == 'e')){}
        if (i == n || (s[i] != 'o'))flag = false;

        while (i++ < n && (s[i] == 'o')){}
        if (i == n || (s[i] != 'w'))flag = false;

        while (i++ < n && (s[i] == 'w')){}
        if (i != n) flag = false;

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}