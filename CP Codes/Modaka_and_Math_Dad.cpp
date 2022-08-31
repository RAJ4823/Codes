#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<int> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int sum1 = 0, sum2 = 0;
        vector<int> a;
        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            a.push_back((i % 2) + 1);
            b.push_back((a[i] % 2) + 1);
            sum1 += a[i];
            sum2 += b[i];
            if (sum1 == n || sum2 == n)
                break;
        }

        if (sum1 == sum2)
        {
            if (a[0] > b[0])
                print(a);
            else
                print(b);
            continue;
        }

        if (sum1 == n)
        {
            print(a);
            continue;
        }

        if (sum2 == n)
        {
            print(b);
            continue;
        }
    }
    return 0;
}