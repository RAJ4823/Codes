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

ll fun(ll i, vvll &arr)
{

    ll notpick = fun(i - 1);
    ll pick = 0;
    if (arr[i - 1][1] < arr[i][0])
        pick = arr[i][2] + fun(i - 1);
    return max(pick, notpick);
}

int main()
{
    ll n;
    cin >> n;

    vvll arr(n, vll(3, 0));
    f(i, n) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    cout << fun(n - 1, arr);
    return 0;
}