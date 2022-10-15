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

double find(int diff, int count)
{
    int match = 0;
    int sum = 0;
    for (int i = 0; i <= count; i++)
    {
        sum = i;
        for (int j = i; j <= count; j++)
        {
            sum--;
        }
        if (diff == sum)
            match++;
    }
    return (2 * match);
}
int main()
{

    string a, b;
    cin >> a >> b;
    int n = a.length();
    int ca = 0, cb = 0, count = 0;
    f(i, n)
    {
        ca += (a[i] == '+') ? (1) : (-1);
        if (b[i] == '?')
        {
            count++;
            continue;
        }
        cb += (b[i] == '+') ? (1) : (-1);
    }
    double ans = 0;
    if (count == 0)
        ans = 1;
    else if (abs(ca - cb) > count)
        ans = 0;
    else
    {
        int tot = pow(2, count);
        int pos = find(abs(ca - cb), count);
        ans = (double)(pos / tot);
    }
    printf("%.12f", ans);
    return 0;
}