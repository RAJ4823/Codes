//?https://www.codingninjas.com/codestudio/problems/house-robber_839733
//* Using logic & code of problem : Maxsum_non_adjacent_elements

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(vector<int> &nums) {
    int n = nums.size();
    ll prev1, prev2 = 0, curr = 0;
    prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        ll pick = 0, notp = 0;
        notp = prev1;
        if (n >= 2)
            pick = nums[i] + prev2;
        curr = max(pick, notp);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];
    vector<int> temp1, temp2;
    for(int i=0; i<n; i++)
    {
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
    }
    return max(f(temp1), f(temp2));
}