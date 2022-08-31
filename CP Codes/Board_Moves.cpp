#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n = 499993;
    ll x = 41664916690999888;
    ll ans = n;
    int count = 0;
    int y = 12;

    while(n *= x) {
        n*=2;
        count++;
    } 
    while(y--) {
        ans *= 2;
    }
    cout << count << endl;
    cout << ans << endl;
    return 0;
}