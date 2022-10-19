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
        vll v(n);
        f(i, n) cin >> v[i];

        ll i = 0, j = n - 1;
        ll sum_a = 0, sum_b = 0;
        ll count = 0, ans_a = 0, ans_b = 0;

        while (i <= j)
        {
            if (count % 2 == 0)
            {
                ll temp_sum = 0;

                while (temp_sum <= sum_b && i <= j)
                    temp_sum += v[i++];

                ans_a += temp_sum;
                sum_a = temp_sum;
            }
            else
            {
                ll temp_sum = 0;

                while (temp_sum <= sum_a && i <= j)
                    temp_sum += v[j--];

                ans_b += temp_sum;
                sum_b = temp_sum;
            }
            count++;
        }
        
        cout << count << ' ' << ans_a << ' ' << ans_b << ' ' << endl;
    }
    return 0;
}