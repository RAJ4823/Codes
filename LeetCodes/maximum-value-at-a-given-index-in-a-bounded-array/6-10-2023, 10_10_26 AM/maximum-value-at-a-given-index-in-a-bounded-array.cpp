// Link: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-value-at-a-given-index-in-a-bounded-array
 *  RUNTIME: 11 ms
 *  MEMORY: 6 MB
 *  DATE: 6-10-2023, 10:10:26 AM
 *
 */

// Solution:

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if(n == 1) return maxSum;
        if(n == maxSum) return 1;

        int remSum = maxSum - n;
        int left = index, right = index;

        int x = 1, ans = 1;
        while(remSum >= (right - left + 1)) {
            if(left == 0 && right == n-1) {
                ans += (remSum / n);
                break;
            }

            remSum -= (right - left + 1); 
            ans++;
            
            left = max(left - 1, 0);
            right= min(right+ 1, n-1);
        }
        return ans;
    }
};
