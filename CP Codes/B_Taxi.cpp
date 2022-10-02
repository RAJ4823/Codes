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
    int n, cnt[5] = {0};
    int ans = 0;
    cin >> n;

    f(i, n)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ans += cnt[4];
    int y = min(cnt[1], cnt[3]);
    cnt[1] -= y;
    cnt[3] -= y;
    ans += y;
    if (cnt[3] > 0)
        ans += cnt[3];
    y = cnt[2] / 2;
    ans += y;
    cnt[2] -= y * 2;
    if (cnt[2] == 1)
    {
        if (cnt[1] <= 2)
        {
            cnt[1] = 0;
            ans++;
        }
        else
        {
            cnt[1] -= 2;
            ans++;
        }
    }
    ans += (cnt[1] / 4);
    if (cnt[1] % 4 > 0)
        ans++;
    cout << ans << endl;
    return 0;
}