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
    cin>>t;

    while(t--)
    {
        ll n, k, sum = 0;
        cin >> n >> k;
        vll v, arr(n);

        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        for(int i=1; i<n; i++) {
            int diff = abs(arr[i] - arr[i-1]);
            v.push_back(diff);
            sum += diff;
        }
        sort(v.begin(), v.end());

        for(int i=1; i<k; i++) {
            sum -= v.back();
            v.pop_back();
        }
        cout << sum << endl;
    }
    return 0;
}