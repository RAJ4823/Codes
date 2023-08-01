// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kids-with-the-greatest-number-of-candies
 *  RUNTIME: 7 ms
 *  MEMORY: 8.9 MB
 *  DATE: 4-17-2023, 9:48:26 AM
 *
 */

// Solution:

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size(), maxi = 0;
        vector<bool> ans(n, false);
        for(int i=0; i<n; i++) maxi = max(maxi, candies[i]);
        for(int i=0; i<n; i++) {
            if(extra + candies[i] >= maxi)  {
                ans[i] = true;
            }
        }
        return ans;
    }
};
