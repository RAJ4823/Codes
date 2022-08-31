#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    if(min(n,m) %2) {
        cout << "Akshat\n";
    } else {
        cout << "Malvika\n";
    }
    return 0;
}