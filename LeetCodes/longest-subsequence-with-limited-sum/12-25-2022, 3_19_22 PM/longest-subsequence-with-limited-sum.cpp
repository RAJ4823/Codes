// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-subsequence-with-limited-sum
 *  RUNTIME: 19 ms
 *  MEMORY: 13.6 MB
 *  DATE: 12-25-2022, 3:19:22 PM
 *
 */

// Solution:

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> sums(n, 0), ans(m);
        sort(nums.begin(), nums.end());
        sums[0] = nums[0];
        for(int i=1;i<n;i++) {
            sums[i] = sums[i-1] + nums[i]; 
        }
        for(int i=0;i<m;i++) {
            int maxSize = upper_bound(sums.begin(), sums.end(), queries[i]) - sums.begin();
            ans[i] = maxSize;
        }
        return ans;
    }
};
