#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxSubArraySum(int a[], int n)
{
    int cur_sum = 0,max_sum = INT_MIN;
    for(int i=0; i<n; i++)
    {
        cur_sum += a[i];
        if(cur_sum > max_sum)
            max_sum = cur_sum;
        if(cur_sum < 0)
            cur_sum = 0;
    }
    return max_sum;
}

int main()
{
    int n = 10;
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3, 0, -1};
    //Max sum = 4 -1 -2 1 5 = 7
    
    int max_sum = maxSubArraySum(a, n);
    cout << max_sum << endl;
    return 0;
}