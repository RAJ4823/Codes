#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int s, n;
    cin >> s >> n;
    int count = n;
    
    vector<pair<int,int> > v;
    int x,y;
    for (int i = 0; i < n; i++)
    {   
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (s > v[i].first)
        {
            s += v[i].second;
            count--;
        }
        else
        {
            break;
        }
    }

    if (count)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}