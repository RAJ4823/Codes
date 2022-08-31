#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    cin >> s;
    int upp = 0, low = 0;

    for(int i=0; i<s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            upp++;
        else
            low++;
    }
    if(upp > low) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    cout << s << endl;
    return 0;
}