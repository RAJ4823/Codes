// Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-limit-of-balls-in-a-bag
 *  RUNTIME: 193 ms
 *  MEMORY: 56.1 MB
 *  DATE: 3-8-2023, 11:06:33 AM
 *
 */

// Solution:

class Solution {
public:
    long long  calcOp(long long mid, vector<int> &nums) {
        long long count = 0;
        for(long long val: nums)  {
            count += (val / mid);
            if(val % mid == 0) 
                count--;
        }
        return count;
    }
    int minimumSize(vector<int>& nums, int op) {
        long long low = 1, high = 0;
        for(long long val: nums) high = max(high, val);

        int ans = 0;
        while(low <= high) {
            long long mid = (low + high)/2;
            if(calcOp(mid, nums) > op) {
                low = mid + 1;
            } else {
                ans = mid;
                high= mid - 1;
            }
        }
        return ans;
    }
};
