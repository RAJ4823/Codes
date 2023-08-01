// Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-subarrays-with-fixed-bounds
 *  RUNTIME: 123 ms
 *  MEMORY: 70.4 MB
 *  DATE: 3-4-2023, 9:59:47 AM
 *
 */

// Solution:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minStart = -1, maxStart = -1;
        int prev = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                minStart = -1;
                maxStart = -1;
                prev = i+1;
            }
            if(nums[i] == minK) minStart = i;
            if(nums[i] == maxK) maxStart = i;
            if(minStart != -1 && maxStart != -1) {
                int curr = min(minStart, maxStart);
                ans += abs(curr - prev + 1);
            }
        }
        return ans;
    }
};
