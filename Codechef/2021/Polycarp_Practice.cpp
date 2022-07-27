#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k,mx=-1,ans;
    cin>>n>>k;

    int a[n+10],b[n+10],c[k+10];

    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    
    for(i=0;i<k;i++){
        mx=-1;
        for(j=0;j<n;j++){
            if(b[j]>mx)
            {
                mx=b[j];
                ans=j;
            }
        }
        b[ans]=0;
        c[i]=ans;
    }

    sort(c,c+k);
    ans=0;

    for(i=0;i<k;i++)
        ans+=a[c[i]];

    cout<<ans<<endl;
    if(k==1){
        cout<<n<<endl;
    }
    else{
        for(i=0;i<k-1;i++)
        {
            if(i==0)
                ans=c[i]+(c[i+1]-c[i]);
            else
                ans=c[i+1]-c[i];

            cout<<ans<<" ";
        }
        ans=n-c[k-1];
        cout<<ans<<endl;
    }
return 0;
}
