// Link: https://leetcode.com/problems/missing-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: missing-number
 *  RUNTIME: 13 ms
 *  MEMORY: 20.3 MB
 *  DATE: 2-20-2024, 1:02:25 PM
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
