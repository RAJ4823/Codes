#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    double n;
    cin >> n;
    double sq = sqrt(n);
    double x = round(sq);

    if (x < sq)
    {
        cout << x + (x + 1) << endl;
    }
    else
    {
        cout << x + x << endl;
    }
}