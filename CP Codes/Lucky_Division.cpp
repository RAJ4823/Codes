#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL

    int n;
    cin >> n;
    int lucky[12] = {4,7,44,47,74,77,444,447,477,777,774,744};
    bool ans = false;

    for(int i=0; i<12; i++) {
        if(n%lucky[i] == 0) {
            ans = true;
            break;
        }
    }
    
    if(ans)
        cout << "YES\n";
    else 
        cout << "NO\n";

    // cout << s << endl;
    return 0;
}