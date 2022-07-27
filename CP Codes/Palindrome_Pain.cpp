#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print1(int x, int y, char c1, char c2)
{
    for (int i = 0; i < x / 2; i++)
        cout << c1;
    for (int i = 0; i < y; i++)
        cout << c2;
    for (int i = 0; i < x / 2; i++)
        cout << c1;
    cout << endl;
}

void print2(int x, int y, char c1, char c2)
{
    cout << c2;
    for (int i = 0; i < x / 2; i++)
        cout << c1;
    for (int i = 2; i < y; i++)
        cout << c2;
    for (int i = 0; i < x / 2; i++)
        cout << c1;
    cout << c2 << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        if ((x % 2 && y % 2) || min(x, y) == 1)
            cout << "-1\n";
        else
        {
            if (x % 2 == 0) {
                print1(x, y, 'a', 'b');
                print2(x, y, 'a', 'b');
            }
            else {
                print1(y, x, 'b', 'a');
                print2(y, x, 'b', 'a');
            }
        }
    }
    return 0;
}