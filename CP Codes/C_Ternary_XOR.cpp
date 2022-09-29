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
        ll n;
        cin >> n;
        string num, a, b;
        cin >> num;
        a = b = num;
        bool flag = false;
        f(i, n)
        {
            if (flag)
            {
                a[i] = '0';
                b[i] = num[i];
                continue;
            }

            if (num[i] == '1')
            {
                a[i] = '1';
                b[i] = '0';
                flag = true;
            }
            else
            {
                a[i] = (num[i] == '2') ? '1' : '0';
                b[i] = a[i];
            }
        }
        cout << a << "\n"
             << b << endl;
    }
    return 0;
}