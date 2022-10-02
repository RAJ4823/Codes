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

int find(vll &alpha, int j)
{
    int count = 1;
    int p = j;
    while (p != -1)
    {
        p = alpha[p];
        if (p == j)
            return count;
        count++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string s, ans = "";
        cin >> s;
        vll alpha(26, -1), beta(26, 1);

        f(i, n)
        {
            int ch = s[i] - 'a';
            if (alpha[ch] == -1)
            {
                f(j, 26)
                {
                    if (beta[j] != 0 && j != ch)
                    {
                        alpha[ch] = j;
                        int k = find(alpha, j);
                        if (k == -1 || k == 26)
                        {
                            beta[j] = 0;
                            break;
                        }
                    }
                }
            }
            ans += (alpha[ch] + 'a');
        }
        cout << ans << endl;
    }
    return 0;
}
