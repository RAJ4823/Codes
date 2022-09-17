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
    int n;
    cin >> n;
    int x, zero = 0, one = 0, ans = 0;

    f(i, n)
    {
        cin >> x;
        if (x == 0)
            zero++;
        else
        {
            one++;
            ans = max(ans, zero);
            zero = max(0, --zero);
        }
    }
    ans = max(ans, zero) + one;
    if(ans == one)
        ans--;
    cout << ans << endl;
    return 0;
}