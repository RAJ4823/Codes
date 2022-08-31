
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;
	cin >> t;
	while(t--)
	{
        int r,l,n;
        string s;
		cin >> n;
        cin >> s;

		if(s[0]=='>')   
            cout << "0\n";
		else if(s[n-1]=='<')    
            cout << "0\n";
		else
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='>')
				{
                    r=i;
                    break;
				}
			}
			for(int i=0;i<n;i++)
			{
				 if(s[i]=='<')l=i;
			}
			cout << min(r,n-l-1) << "\n";
		}
	}
	return 0;
}