// Link: https://leetcode.com/problems/majority-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: majority-element
 *  RUNTIME: 7 ms
 *  MEMORY: 19.5 MB
 *  DATE: 8-2-2023, 4:18:22 PM
 *
 */

// Solution:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, ans = 0;
        for(auto &val: nums) {
            if(count == 0) {
                ans = val;
            }
            if(val == ans) {
                count++;
            } else {
                count--;
            }
        }
        return ans;
    }
};
