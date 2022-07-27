#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int maxi =a[n-1];

	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<=maxi)
			b[i]=(maxi-a[i])+1;
		else
        {
			b[i]=0;
			maxi=a[i];
		}
	}
	for(int i=0;i<=n-2;i++)
		cout<<b[i]<<" ";

	cout<<'0'<<endl;
	return 0;
}