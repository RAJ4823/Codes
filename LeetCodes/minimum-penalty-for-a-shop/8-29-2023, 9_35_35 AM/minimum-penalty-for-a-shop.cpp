// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-penalty-for-a-shop
 *  RUNTIME: 24 ms
 *  MEMORY: 10.8 MB
 *  DATE: 8-29-2023, 9:35:35 AM
 *
 */

// Solution:

class Solution {
public:
    int bestClosingTime(string arr) {
        int n = arr.size();
        int ans = -1, maxi = 0, sum = 0;
        
        for(int i=0; i<n; i++) {
            sum = (arr[i] == 'Y') ? sum + 1 : sum - 1;
            if(sum > maxi) {
                maxi = sum;
                ans = i;
            }
        }
        return ans+1;
    }
};
