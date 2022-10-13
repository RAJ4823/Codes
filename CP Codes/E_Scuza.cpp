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
        int n, q;
        cin >> n >> q;
        vll arr(n + 1), sum(n + 1, 0), maxi(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
            maxi[i] = max(maxi[i - 1], arr[i]);
        }

        while (q--)
        {
            int x;
            cin >> x;
            ll in = upper_bound(maxi.begin(), maxi.end(), x) - maxi.begin();
            cout << sum[in - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}