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
        int n;
        string s;
        cin >> n;
        cin >> s;

        if (n % 2)
        {
            cout << "NO\n";
        }
        else
        {
            int alpha[26] = {0};
            for (int i = 0; i < n; i++)
            {
                int val = s[i] - 97;
                alpha[val]++;
            }

            int maxi = 0;
            for (int i = 0; i < 26; i++)
                if (alpha[i] > maxi)
                    maxi = alpha[i];

            if (maxi > (n / 2))
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                sort(s.begin(), s.end());

                for (int i = 0; i < n / 2; i++)
                    cout << s[i] << s[n - i - 1];
                cout << endl;
            }
        }
    }
    return 0;
}