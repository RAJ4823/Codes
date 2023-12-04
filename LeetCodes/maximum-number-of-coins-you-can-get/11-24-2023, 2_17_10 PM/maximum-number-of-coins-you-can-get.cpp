// Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-coins-you-can-get
 *  RUNTIME: 93 ms
 *  MEMORY: 53.8 MB
 *  DATE: 11-24-2023, 2:17:10 PM
 *
 */

// Solution:

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), ans = 0;
        int i = 0, j = n - 2;

        while(i < j) {
            ans += piles[j];
            i += 1;
            j -= 2;
        }
        return ans;
    }
};
