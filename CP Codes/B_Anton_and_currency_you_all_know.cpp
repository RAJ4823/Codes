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

    string n;
    cin >> n;
    ll j = -1, m = n.length();
    f(i, m)
    {
        if ((n[i] - '0') % 2 == 0)
        {
            j = i;
            if (n[i] < n[m - 1])
                break;
        }
    }

    if (j == -1)
        cout << j << endl;
    else
    {
        char temp = n[j];
        n[j] = n[m - 1];
        n[m - 1] = temp;
        cout << n << endl;
    }
    return 0;
}