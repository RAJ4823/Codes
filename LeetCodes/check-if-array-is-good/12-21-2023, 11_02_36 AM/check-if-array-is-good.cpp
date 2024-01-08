// Link: https://leetcode.com/problems/check-if-array-is-good

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-array-is-good
 *  RUNTIME: 7 ms
 *  MEMORY: 23.1 MB
 *  DATE: 12-21-2023, 11:02:36 AM
 *
 */

// Solution:

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int maxCount = 0;
        vector<bool> set(n, false);
        for(int num: nums){
            if(num > n) return false;
            else if(num == n) maxCount++;
            else if(set[num]) return false;
            else set[num] = true;
        }
        return maxCount == 2;
    }
};
