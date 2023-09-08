// Link: https://leetcode.com/problems/most-frequent-even-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-frequent-even-element
 *  RUNTIME: 41 ms
 *  MEMORY: 38.2 MB
 *  DATE: 8-18-2023, 11:00:29 AM
 *
 */

// Solution:

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto &val: nums) {
            if(!(val & 1)) {
                count[val]++;
            }
        }
        int ans = -1, freq = 0;
        for(auto &x: count) {
            if(x.second > freq) {
                ans = x.first;
                freq = x.second;
            } else if(x.second == freq) {
                ans = min(ans, x.first);
            }
        }
        return ans;
    }
};
