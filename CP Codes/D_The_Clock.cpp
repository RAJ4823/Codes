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
int a[16] = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};

int getMinutes(string s)
{
    int hh = ((s[0] - 48) * 10 + (s[1] - 48));
    int mm = ((s[3] - 48) * 10 + (s[4] - 48));
    return (hh * 60 + mm);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        map<int, bool> m;
        int x, ans = 0;

        cin >> s;
        cin >> x;

        f(i, 16) m[a[i]] = true;

        int z = getMinutes(s);
        int y = z;

        while (true)
        {
            if (m[y])
                ans++;

            y = (y + x) % 1440;
            if (y == z)
                break;
        }

        cout << ans << endl;
    }
    return 0;
}