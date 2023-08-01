// Link: https://leetcode.com/problems/single-number-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: single-number-iii
 *  RUNTIME: 7 ms
 *  MEMORY: 10.7 MB
 *  DATE: 7-4-2023, 5:38:04 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnt;
        vector<int> ans;
        for(auto &val: nums) {
            cnt[val]++;
        }
        for(auto &x: cnt) {
            if(x.second == 1) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
