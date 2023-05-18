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
    ll N, B;
    cin >> N >> B;
    vll per(N), bonus(N, 0);
    f(i, N) cin >> per[i];

    // ff(i, 0, N)
    // {
    //     int left = (i == 0) ? N - 1 : i - 1;
    //     if (per[i] > per[left])
    //         bonus[i] = B + bonus[left];
    // }
    // ff(i, 0, N)
    // {
    //     int right = (i == N - 1) ? 0 : i + 1;
    //     if (per[i] > per[right])
    //         bonus[i] = B + bonus[right];
    // }

    f(i, N)
    {
        int left = (i == 0) ? N - 1 : i - 1;
        int right = (i == N - 1) ? 0 : i + 1;

        if (per[i] > per[left])
        {
            bonus[i] = B + bonus[left];
        }
        if (per[i] > per[right])
        {
            bonus[i] = B + bonus[right];
        }
        if (per[i] > per[left] && per[i] > per[right])
        {
            bonus[i] = max(B + bonus[left], B + bonus[right]);
        }
    }
    f(i, N) cout << bonus[i] << ' ';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        
        
    }
    return 0;
}