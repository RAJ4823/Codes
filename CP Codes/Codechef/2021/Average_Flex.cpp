#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0; i<n; i++)
        cin >> arr[i];

        sort(arr,arr+n);

        int sum=0;

        for(int i=0; i<n; i++) {
            int a=0, b=0;

            for(int j=0; j<n; j++) {
                if(arr[j] <= arr[i]) {
                    a++;
                }
                else {
                    b++;
                }
            }
            if(a-1 >= b) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}