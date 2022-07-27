#include <bits/stdc++.h>
#define ll long long
const int N = 1000001;
using namespace std;

ll factInv[N + 1];
ll numInv[N + 1];
ll fact[N + 1];

void InvNum(ll MOD)
{
    numInv[0] = numInv[1] = 1;
    for (int i = 2; i <= N; i++)
        numInv[i] = numInv[MOD % i] * (MOD - MOD / i) % MOD;
}
void InvFact(ll MOD)
{
    factInv[0] = factInv[1] = 1;
    for (int i = 2; i <= N; i++)
        factInv[i] = (numInv[i] * factInv[i - 1]) % MOD;
}
void Fact(ll MOD)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll Binomial(ll N, ll R, ll MOD)
{
    ll ans = ((fact[N] * factInv[R]) % MOD * factInv[N - R]) % MOD;
    return ans;
}

// Driver Code
int main()
{
    ll MOD = 1000000007;
    InvNum(MOD);
    InvFact(MOD);
    Fact(MOD);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, l, r, R, j;
        cin >> n >> l >> r;

        for (ll i = l; i <= r; i++)
        {
            j = abs(i);
            if (n % 2 == (j % 2))
            {
                R = (n / 2) - (j / 2);
                cout << Binomial(n, R, MOD) << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
