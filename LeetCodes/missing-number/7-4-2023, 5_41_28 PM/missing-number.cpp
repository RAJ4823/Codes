// Link: https://leetcode.com/problems/missing-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: missing-number
 *  RUNTIME: 23 ms
 *  MEMORY: 18 MB
 *  DATE: 7-4-2023, 5:41:28 PM
 *
 */

// Solution:

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> store(nums.size() + 1, false);
        for(auto &val: nums)
            store[val] = true;

        int ans = 0;
        for(int i=0; i<store.size(); i++) {
            if(!store[i]) {
                return i;
            }
        }
        return 0;
    }
};
