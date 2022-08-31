#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,a,b;
    cin >> n >> a >> b;

    cout << n-max(a+1, n -b) + 1 << endl;
    return 0;
}