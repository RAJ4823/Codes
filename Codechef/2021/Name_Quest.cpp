#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string a,b;
    cin>>a>>b;

	int la=a.size();
	int lb=b.size();
	int i;
	int p1,p2;

	for(i=1,p1=1;p1<=lb;p1++)
	{
		if(a[i]==b[p1]) i++;
		if(i>la) break;
	}

	for(i=la,p2=lb;p2>=1;p2--)
	{
		if(a[i]==b[p2]) i--;
		if(i<1) break;
	}

	cout<<max(0,p2-p1);
	return 0;
}