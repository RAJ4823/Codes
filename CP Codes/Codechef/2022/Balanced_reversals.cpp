#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int nz = 0, z = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i]-48)
                nz++;
            else
                z++;
        }
        while (z--)
            cout << "0";
        while (nz--)
            cout << "1";
        cout << endl;
    }
    return 0;
}