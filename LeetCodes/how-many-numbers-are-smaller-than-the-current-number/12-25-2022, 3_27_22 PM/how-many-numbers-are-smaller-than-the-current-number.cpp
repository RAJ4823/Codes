// Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: how-many-numbers-are-smaller-than-the-current-number
 *  RUNTIME: 9 ms
 *  MEMORY: 10.4 MB
 *  DATE: 12-25-2022, 3:27:22 PM
 *
 */

// Solution:

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums, ans;
        sort(arr.begin(), arr.end());
        for(auto &x: nums) {
            int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};
