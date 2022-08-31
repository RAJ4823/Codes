#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;

    while(t--)
    {
        int n,m,a,b, x, y, count=0;

        cin>>n>>m;

        for(a=1; a<=n; a++)
        {
            for(b=a+1; b<=n; b++)
            {
                x = m%a;
                y = m%b;

                if(y%a == x%b)
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}