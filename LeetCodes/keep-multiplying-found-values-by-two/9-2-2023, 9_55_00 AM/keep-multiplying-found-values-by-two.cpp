// Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: keep-multiplying-found-values-by-two
 *  RUNTIME: 3 ms
 *  MEMORY: 10.7 MB
 *  DATE: 9-2-2023, 9:55:00 AM
 *
 */

// Solution:

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> mp;

        for(auto &val: nums) {
            if(val % original == 0) {
                mp[val] = true;
            }
        }
        while(mp[original])    
            original *= 2;
        return original;
    }
};
