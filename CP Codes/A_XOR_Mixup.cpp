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
        ll n;
        cin >> n;
        vll v(n);
        ll sum = 0;
        bool flag = true;
        f(i, n)
        {
            cin >> v[i];
        }
        f(i, n)
        {
            flag = true;
            f(j, n)
            {
                if (i == j)
                    continue;
                if (flag)
                {
                    sum = v[j];
                    flag = false;
                }
                else
                {
                //     db2(sum, v[j]);
                    sum = (sum ^ v[j]);
                }
            }
            if (sum == v[i])
            {
                cout << v[i] << endl;
                break;
            }
        }
    }
    return 0;
}