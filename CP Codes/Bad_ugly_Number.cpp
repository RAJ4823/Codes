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
        n--;

        if (!n)
        {
            cout << "-1\n";
            continue;
        }
        cout << "2";
        
        while (n--)
            cout << "3";

        cout << "\n";
    }
    return 0;
}