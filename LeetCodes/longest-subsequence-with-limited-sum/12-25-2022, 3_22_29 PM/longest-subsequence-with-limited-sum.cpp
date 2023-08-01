// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-subsequence-with-limited-sum
 *  RUNTIME: 15 ms
 *  MEMORY: 13.4 MB
 *  DATE: 12-25-2022, 3:22:29 PM
 *
 */

// Solution:

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++) {
            nums[i] += nums[i-1]; 
        }
        for(int i=0;i<m;i++) {
            int maxSize = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans[i] = maxSize;
        }
        return ans;
    }
};
