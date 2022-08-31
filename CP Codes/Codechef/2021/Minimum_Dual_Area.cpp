/*  
    Made By : Raj Patel
    Date : 14/6/2021
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

void DualArea()
{
    int n;
    cin >> n;

    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    multiset<int> X;
    multiset<int> Y;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        x.push_back({a, b});
        y.push_back({b, a});
        X.insert(a);
        Y.insert(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int H1 = 0; //height1
    int H2 = 0; //height2
    int h1Max = 0;
    int h1Min = LONG_MAX;
    int Area = LONG_MAX;

    for (int i = 0; i < n - 1; ++i)
    {

        h1Max = max(h1Max, x[i].second);
        h1Min = min(h1Min, x[i].second);
        H1 = h1Max - h1Min;
        auto it = Y.find(x[i].second);
        Y.erase(it);
        H2 = *Y.rbegin() - *Y.begin();
        int newArea = (x[i].first - x[0].first) * H1 +
                        (x[n - 1].first - x[i + 1].first) * H2;
        Area = min(Area, newArea);
    }
    int W1 = 0; //width1
    int W2 = 0; //width2
    int w1Max = 0;
    int w1Min = LONG_MAX;
    for (int i = 0; i < n - 1; ++i)
    {
        w1Max = max(w1Max, y[i].second);
        w1Min = min(w1Min, y[i].second);
        W1 = w1Max - w1Min;
        auto it = X.find(y[i].second);
        X.erase(it);
        W2 = *X.rbegin() - *X.begin();
        int newArea = (y[i].first - y[0].first) * W1 +
                        (y[n - 1].first - y[i + 1].first) * W2;
        Area = min(Area, newArea);
    }
    if (Area == LONG_MAX)
        Area = 0;
    cout << Area << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;
    int _=1;
    while(t--)
    {
        DualArea();
    }
    return 0;
}
