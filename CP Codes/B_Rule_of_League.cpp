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

void print(int n, int m)
{
    int play = 1, count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (count < m)
        {
            count++;
        }
        else
        {
            play = i;
            count = 1;
        }
        cout << play << ' ';
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int maxi = max(x, y), mini = min(x, y);
        if (maxi == 0 || mini > 0)
        {
            cout << -1;
        }
        else
        {
            if ((n - 1) % maxi == 0)
                print(n, maxi);
            else
                cout << -1;
        }
        cout << endl;
    }
    return 0;
}