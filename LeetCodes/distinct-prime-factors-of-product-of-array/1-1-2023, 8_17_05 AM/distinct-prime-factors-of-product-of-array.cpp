// Link: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: distinct-prime-factors-of-product-of-array
 *  RUNTIME: 34 ms
 *  MEMORY: 18.8 MB
 *  DATE: 1-1-2023, 8:17:05 AM
 *
 */

// Solution:

#define ll long long int
class Solution {
private:
    void primeFactors(ll n, unordered_set<ll> &s)
    {
        if(n % 2 == 0)  s.insert(2);
        while (n % 2 == 0)  n = n/2;
        
        for (ll i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                s.insert(i);
                n = n/i;
            }
        }
        
        if (n > 2)  s.insert(n);
    }
    
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int count = 0;
        unordered_set<ll> s;
        for(auto &val:nums) {
            primeFactors(val, s);
        } 
        return s.size();
    }
};
