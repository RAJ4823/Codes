// Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimized-maximum-of-products-distributed-to-any-store
 *  RUNTIME: 215 ms
 *  MEMORY: 84.6 MB
 *  DATE: 3-9-2023, 10:45:06 AM
 *
 */

// Solution:

class Solution {
public:
    long long countStores(long long mid, vector<int> &arr) {
        long long count = 0;
        for(long long val: arr) {
            count += ceil(1.0 * val / mid);
        }
        return count;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        long long low = 1, high = 0;
        for(long long val: arr) high = max(high, val);
        long long ans = high;
        while(low <= high) {
            long long mid = (low + high) / 2;
            long long cnt = countStores(mid, arr);
            if(cnt <= n) {
                // if(cnt == n) ans = min(ans, mid);
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
