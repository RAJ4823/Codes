// Link: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-collisions-of-monkeys-on-a-polygon
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 1-29-2023, 8:38:06 AM
 *
 */

// Solution:

#define ll long long int
#define MOD 1000000007

class Solution {
public:
    int power(ll base, ll n)
     {
        ll ans = 1;
        while(n>0)
        {
            if(n%2) ans = (ans*base)%MOD;
            base = (base%MOD * base%MOD)%MOD;

            n/=2;
        }
        return (ans % MOD);
     }
    
     int monkeyMove(int n) {
        ll base = 2, y = n;
        int ans = (power(2, y) - 2) % MOD;
         if(ans < 0) {
             ans = MOD + ans;
         }
        return ans;
    }
};
