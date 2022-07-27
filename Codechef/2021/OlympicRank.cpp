#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
	    int G1,S1,B1,G2,S2,B2;
	    cin >> G1  >> S1 >> B1 >> G2 >> S2 >> B2;
	    
	    if((G1+S1+B1) > (G2+S2+B2)){
	        cout << "1\n";
	    }
	    else{
	        cout << "2\n";
	    }
	}
	return 0;
}
