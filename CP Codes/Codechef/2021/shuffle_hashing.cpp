#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
    ll t = 1;
    cin >> t;

    while (t--)
    {
        string p, h;
        cin >> p >> h;

        ll P = p.length();
        ll H = h.length();

        bool right = false;
        sort(p.begin(), p.end());

        for (ll i = 0; i < H - P + 1; ++i)
        {
            string temp = h.substr(i, P); 
            sort(temp.begin(), temp.end());

            if(p == temp)
            {
                right = true;
                break;
            }
        }

        if(right) cout << "YES\n";
        else cout <<"NO\n";
    }
}