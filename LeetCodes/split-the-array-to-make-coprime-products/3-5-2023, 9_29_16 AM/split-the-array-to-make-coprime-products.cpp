// Link: https://leetcode.com/problems/split-the-array-to-make-coprime-products

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: split-the-array-to-make-coprime-products
 *  RUNTIME: 842 ms
 *  MEMORY: 19.7 MB
 *  DATE: 3-5-2023, 9:29:16 AM
 *
 */

// Solution:

#define ll long long
class Solution
{
public:
    unordered_map<ll, ll> mp;
    ll eval1(ll i, ll val, ll limit)
    {
        for (ll j = 2; j <= limit; j++)
        {
            if (val % j == 0 && mp[j] == 0)
                mp[j] = i + 1;
            while (val % j == 0)
                val /= j;
        }
        return val;
    }
    
    ll eval2(ll val, ll &k, ll limit)
    {
        for (ll j = 2; j <= limit; j++)
        {
            if (val % j == 0) 
                k = max(mp[j], k);
            while (val % j == 0)
                val /= j;
        }
        return val;
    }
    
    int findValidSplit(vector<int> &nums)
    {
        ll n = nums.size();
        for (ll i = n - 1; i >= 0; i--)
        {
            ll val = eval1(i, nums[i], sqrt(nums[i]));
            if (val > 1 && mp[val] == 0)
                mp[val] = i + 1;
        }
        ll k = 1;
        for (ll i = 0; i < k; i++)
        {
            ll val = eval2(nums[i], k, sqrt(nums[i]));
            if (val > 1) k = max(k, mp[val]);
            
        }
        if(k != n) return k - 1;
        return -1;
    }
};
