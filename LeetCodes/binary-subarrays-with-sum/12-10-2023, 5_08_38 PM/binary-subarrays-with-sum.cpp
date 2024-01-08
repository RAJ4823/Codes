// Link: https://leetcode.com/problems/binary-subarrays-with-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-subarrays-with-sum
 *  RUNTIME: 22 ms
 *  MEMORY: 30.2 MB
 *  DATE: 12-10-2023, 5:08:38 PM
 *
 */

// Solution:

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, count = 0, n = nums.size();
        vector<int> prefix(n+1, 0);
        prefix[0] = 1;
        for(int i=0; i<n; i++) {
            count += nums[i];
            if(count >= goal) {
                ans += prefix[count - goal];
            }
            prefix[count]++;
        }
        return ans;
    }
};
