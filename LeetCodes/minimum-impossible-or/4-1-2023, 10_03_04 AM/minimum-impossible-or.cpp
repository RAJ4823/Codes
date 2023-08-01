// Link: https://leetcode.com/problems/minimum-impossible-or

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-impossible-or
 *  RUNTIME: 128 ms
 *  MEMORY: 47.7 MB
 *  DATE: 4-1-2023, 10:03:04 AM
 *
 */

// Solution:

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int x = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            if(x == nums[i]) {
                x *= 2;
            } else if(x < nums[i]) {
                break;
            }
        }
        return x;
    }
};
