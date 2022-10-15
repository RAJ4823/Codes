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
        int sdk[9][9] = {0};
        string line;
        int v[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
        f(i, 9)
        {
            cin >> line;
            f(j, 9) sdk[i][j] = line[j] - '0';
            sdk[i][v[i]] = max(1, (sdk[i][v[i]] + 1) % 10);
        }
        f(i, 9)
        {
            f(j, 9) cout << sdk[i][j];
            cout << endl;
        }
    }
    return 0;
}