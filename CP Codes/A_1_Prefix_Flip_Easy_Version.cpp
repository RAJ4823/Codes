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

void calc(vll &len, string &a, string &b)
{
    f(i, a.length())
    {
        if (a[i] != b[i])
        {
            if (i > 0)
                len.push_back(i + 1);
            len.push_back(1);
            if (i > 0)
                len.push_back(i + 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vll len;
        calc(len, a, b);

        cout << len.size() << ' ';
        fauto(i, len) cout << i << ' ';
        cout << endl;
    }
    return 0;
}