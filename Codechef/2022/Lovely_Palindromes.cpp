#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string s;
    cin >> s;
    string r;

    for(int i=s.length()-1; i>=0; i--) {
        r.push_back(s[i]);
    }
    cout << s+r << endl;
    return 0;
}