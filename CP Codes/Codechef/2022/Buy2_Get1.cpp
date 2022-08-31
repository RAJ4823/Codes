#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int y = (n / 3) * 2;

        if ((n - 1) % 3 == 0)
            y += 1;
        if ((n + 1) % 3 == 0)
            y += 2;
        
        cout << x * y << endl;
    }
    return 0;
}
