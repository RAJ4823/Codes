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
#define db1(i) cout << #i << " = " << (i) << "\n";
#define db2(i, value) cout << #i << " = " << (i) << " " << #value << " = " << (value) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    ll n, q, sum = 0;
    cin >> n >> q;
    vll v(n);
    vll fq(n, 0), fValue(n, 0);

    f(i, n)
    {
        cin >> v[i];
        fValue[i] = v[i];
        sum += v[i];
    }

    ll sq = 0, sValue = 0;
    f(index, q)
    {
        ll task, val, i;
        cin >> task;

        if (task == 1)
        {
            cin >> i >> val;
            i--;

            if (sq > fq[i])
            {
                v[i] = sValue;
            }
            else
            {
                v[i] = fValue[i];
            }

            fValue[i] = val;
            fq[i] = index;

            sum -= v[i];
            sum += val;
            cout << sum << endl;
        }
        else
        {
            cin >> val;
            sum = n * val;
            sq = index;
            sValue = val;

            cout << sum << endl;
        }
    }
    return 0;
}