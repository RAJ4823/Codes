// Link: https://leetcode.com/problems/first-bad-version

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-bad-version
 *  RUNTIME: 2 ms
 *  MEMORY: 6.3 MB
 *  DATE: 10-10-2023, 1:25:22 PM
 *
 */

// Solution:

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long
class Solution {
public:
    int firstBadVersion(int n) {
        ll low = 0, high = n;
        ll ans = n;
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(isBadVersion(mid)) {
                ans = min(mid, ans);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
