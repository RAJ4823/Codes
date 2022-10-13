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

char solve()
{
    char v[8][8];
    f(i, 8) f(j, 8) cin >> v[i][j];
    f(i, 8)
    {
        int count1 = 0, count2 = 0;
        f(j, 8)
        {
            if (v[i][j] == 'R')
                count1++;
        }
        f(j, 8)
        {
            if (v[j][i] == 'B')
                count2++;
        }
        if (count1 == 8)
            return 'R';
        if (count2 == 8)
            return 'B';
    }
    return '.';
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}