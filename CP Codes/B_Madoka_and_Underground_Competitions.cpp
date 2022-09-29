#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<char>>
#define vll vector<char>
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
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        r--;
        c--;
        int row = 0, col = (c + r) % n;
        int steps = (n / k);
        vvll v(n, vll(n, '.'));
        f(i, n)
        {
            int j = (col + n - i) % n;
            int count = 0;
            while (count < steps)
            {
                v[i][j] = 'X';
                j = (j + k) % n;
                count++;
            }
        }
        fauto(i, v)
        {
            fauto(j, i) cout << j;
            cout << endl;
        }
    }
    return 0;
}