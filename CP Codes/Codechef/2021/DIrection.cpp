#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;
	 while(test--){
	     int N;
	     cin >> N;
	     int D = N%4;
	     
	     if(D==1) cout << "East" << endl;
	     else if(D==2) cout << "South" << endl;
	     else if(D==3) cout << "West" << endl;
	     else if(D==0) cout << "North" << endl;
	 }
}
