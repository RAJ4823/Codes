// Link: https://leetcode.com/problems/maximize-greatness-of-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximize-greatness-of-an-array
 *  RUNTIME: 137 ms
 *  MEMORY: 78.2 MB
 *  DATE: 3-24-2023, 8:59:59 AM
 *
 */

// Solution:

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> perm = nums;
        int n = nums.size();
        int i=0, j=0, cnt = 0;
        while(i < n && j < n) {
            if(nums[i] >= perm[j]) {
                j++;
            } else  {
                cnt++;
                i++;
                j++;
            }
        }
        return cnt;
    }
};
