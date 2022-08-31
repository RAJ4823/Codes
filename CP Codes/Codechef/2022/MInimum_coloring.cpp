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
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;

        cin >> x1 >> y1;
        cin >> x2 >> y2;

        int x = 1;

        if((x2+1)%x1 == 0 && (y2+1)%y1 == 0) {
            x = 2;
        }
        else if(x1 == y1) {
            x = 1;
        }
        else if(x2 == y2) {
            x = 2;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + 1 == x1 && j + 1 == y1)
                {
                    cout << 1 << " ";
                    continue;
                }
                if (i + 1 == x2 && j + 1 == y2)
                {
                    cout << 2 << " ";
                    continue;
                }
                cout << (x + abs(i - j)) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}