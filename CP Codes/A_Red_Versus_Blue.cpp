#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        double n, a, b;
        cin >> n >> a >> b;

        int y = round(a / (b + 1));
        int x = y, N = n;
        int count = 0;
        while (n >= 0)
        {

            while (y-- && n >= 0)
            {
                n--;
                count++;
                if (count == N)
                    break;
                cout << 'R';
            }
            if (n > 0)
            {
                cout << 'B';
                n--;
                count++;
                y = x;
            }
        }
        cout << endl;
    }
    return 0;
}