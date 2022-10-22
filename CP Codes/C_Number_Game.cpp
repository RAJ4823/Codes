#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll multiset<ll>
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
        int n, x;
        cin >> n;
        multiset<int> ms;

        f(i, n)
        {
            cin >> x;
            ms.insert(x);
        }

        if (n == 1)
        {
            if (*ms.begin() <= 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            int l = 0, ans = 0;
            int r = n;
            while (l <= r)
            {
                int mid = (r + l) / 2;
                multiset<int> temp;
                temp = ms;
                bool flag = 1;
                for (int i = 1; i <= mid; i++)
                {
                    auto a = temp.upper_bound(mid - i + 1);
                    if (a == temp.begin())
                    {
                        flag = 0;
                        break;
                    }
                    else
                    {
                        --a;
                        temp.erase(temp.find(*a));
                        auto b = temp.begin();
                        temp.erase(temp.find(*b));
                        temp.insert(mid + *b + i - 1);
                    }
                }
                if (flag)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}