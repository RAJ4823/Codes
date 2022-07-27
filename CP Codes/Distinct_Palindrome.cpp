#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
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
        int n, x;
        cin >> n >> x;

        if ((n + 1) / 2 >= x)
        {
            char c = 'a';
            int y = x;

            while (x--)
                cout << (c++);
            n -= x;

            if (n % 2)
            {
                y--;
                c--;
            }
            n -= y;
            if (n > 0)
                while (n--)
                    cout << 'a';

            while (n--)
                cout << (c--);
            cout << endl;
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}