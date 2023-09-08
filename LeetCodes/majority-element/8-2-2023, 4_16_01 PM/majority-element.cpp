// Link: https://leetcode.com/problems/majority-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: majority-element
 *  RUNTIME: 19 ms
 *  MEMORY: 19.6 MB
 *  DATE: 8-2-2023, 4:16:01 PM
 *
 */

// Solution:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        unordered_map<int,int> m;
        for(auto &val: nums) {
            m[val]++;
            if(m[val] > (n / 2)) {
                ans = val;
            }
        }
        return ans;
    }
};
