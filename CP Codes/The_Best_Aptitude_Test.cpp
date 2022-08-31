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
#define db1(val) cout << #val << " = " << (val) << "\n";
#define db2(val, y) cout << #val << " = " << (val) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    int t;
    cin >> t;
    float arr1[6][100], arr2[6][100], arr3[6][100];

    while (t--)
    {
        int n;
        cin >> n;
        float v[5] = {0};

        f(i, 6)
        {
            f(j, n)
            {
                cin >> arr1[i][j];
                arr2[i][j] = arr1[i][j];
            }
        }

        f(i, 6)
        {
            f(j, n)
            {
                int k = j;
                while (k > 0 && arr1[i][k] > arr1[i][k - 1])
                {
                    float temp = arr1[i][k];
                    arr1[i][k] = arr1[i][k - 1];
                    arr1[i][k - 1] = temp;

                    k--;
                }
            }
            f(j, n)
            {
                f(k, n)
                {
                    if (arr2[i][k] == arr1[i][j])
                    {
                        arr3[i][k] = j + 1;
                        break;
                    }
                }
            }
            if (i > 0)
                f(j, n)
                    v[i - 1] = v[i - 1] + (arr3[i][j] - arr3[0][j]) * (arr3[i][j] - arr3[0][j]);
        }

        float mini = 1e9;
        int ans;
        f(i, 5)
        {
            if (v[i] < mini)
            {
                mini = v[i];
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
