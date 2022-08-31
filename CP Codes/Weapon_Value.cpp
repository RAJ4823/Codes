#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, count = 0;
        cin >> n;
        //Assigning 0 (zero) to all index
        ll arr[10] = {0};

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int i = 0; i < 10; i++)
            {
                //Counting '1' of each index
                //(s[i] - '0') = integer value of s[i]
                arr[i] += (s[i] - '0');
            }
        }
        for (int i = 0; i < 10; i++)
        {
            //IF occurence of '1' is odd at i index then count++
            //true = 1 so (arr[i]%2 == 1 when arr[i] is odd)
            if (arr[i] % 2)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}

// the_247