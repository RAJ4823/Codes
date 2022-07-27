#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) {
        int n,l,r,k;
        cin >> n >> l >> r >> k;
        vector<int> price;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if(x >= l && x  <= r)
            price.push_back(x);
        }
        sort(price.begin(), price.end());
        int sum = 0, count = 0;

        for(int i=0; i < price.size(); i++) {
            sum += price[i];
            if(sum <= k)
            count++;
            else
            break;
        }

        cout << count << endl;
    }
    return 0;
}