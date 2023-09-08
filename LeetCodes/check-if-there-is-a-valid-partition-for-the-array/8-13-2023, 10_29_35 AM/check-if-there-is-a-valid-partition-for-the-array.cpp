// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-there-is-a-valid-partition-for-the-array
 *  RUNTIME: 138 ms
 *  MEMORY: 83.8 MB
 *  DATE: 8-13-2023, 10:29:35 AM
 *
 */

// Solution:

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        bool curr = true, prev1 = true, prev2 = true, prev3 = true;
        int n = nums.size();
        nums.push_back(0);
        nums.push_back(0);

        for(int i=n-1; i>=0; --i) {
            curr = ((nums[i] == nums[i+1]) && prev2) || ((nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) && prev3) || ((nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2]) && prev3);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
