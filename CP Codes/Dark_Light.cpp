#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    long long int n;
	    int x;
	    cin >> n >>x;
	    if(x == 0)
	    {
	        if(n%4 == 0)
	            cout << "Off\n";
	        else
	            cout << "On\n";
	    }
	    else
	    {
	        if(n%4 == 0)
	            cout << "On\n";
	        else
	            cout << "Ambiguous\n";
	    }
	}
	return 0;
}
