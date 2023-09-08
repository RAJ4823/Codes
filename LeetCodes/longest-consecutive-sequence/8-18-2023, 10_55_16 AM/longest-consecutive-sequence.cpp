// Link: https://leetcode.com/problems/longest-consecutive-sequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-consecutive-sequence
 *  RUNTIME: 380 ms
 *  MEMORY: 67 MB
 *  DATE: 8-18-2023, 10:55:16 AM
 *
 */

// Solution:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &val : nums) {
            set.insert(val);
        }

        int ans = 0;
        for(int val : nums) {
            if(set.find(val-1) == set.end()) {
                int num = val, len = 1;
                while(set.find(num+1) != set.end()) {
                    num++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
