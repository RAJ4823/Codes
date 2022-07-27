#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    **ALL INFORMATIONS WERE CALCUlATED BY RAJ PATEL**

    value of X   -   delay (approx)

    1000000000   -   1.50 Seconds
    500000000    -   1.00 Seconds
    100000000    -   0.50 Seconds
    50000000     -   0.25 Seconds
    1000000      -  <0.01 Seconds

    >1000000000  -   **DO NOT USE**
    <1000000     -   0.00 Seconds

   **Delay time may be different for different processors.**
   **Delay time is different for other loops**
   **In starting it may take some seconds to run**  
*/

//Change value of X here 
#define X 1000000

int main()
{
    string print = "This program is designed to print slower.Nothing is lmpossible, It doesn't mean that Everything is Possible.Everything is Impossible until it's done.Made by Raj Patel.";
    
    cout<<"\nStart >>\n\n";

    for(int i=0; i<= print.size(); i++)
    {
        for(int j=0; j<=X; j++)
        {
            //temperory loop
            // value of Y = delay
        }

        if(print[i]=='.')
        cout<<".\n";
        else
        cout<<print[i];
    }
    return 0;
}