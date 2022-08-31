#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum=0;
        sum=n*(n+1)/2;

        vector<int> A;
        vector<int> B;

        int start=1;
        int end=n;

        while(start<end) {
            A.push_back(start);
            start++;
            B.push_back(start);
            A.push_back(end);
            end--;
            B.push_back(end);
            start++;
            end--;
        }

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        if(sum%2!=0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            
            for(int i=1; i<=n/2; i++)
                cout << A[i-1] << " ";
            cout << endl;
            for(int i=1; i<=n/2; i++)
                cout << B[i-1] << " ";
            cout << endl;
        }
    }
    return 0;
}
