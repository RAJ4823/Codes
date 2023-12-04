// Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: frequency-of-the-most-frequent-element
 *  RUNTIME: 171 ms
 *  MEMORY: 99.3 MB
 *  DATE: 11-18-2023, 10:30:14 AM
 *
 */

// Solution:

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        long long sum = k, maxi = 0;
        
        while(right < nums.size()) {
            sum += (long long)nums[right];
            maxi = (long long)nums[right] * (long long)(right - left + 1);
            if(sum < maxi) {
                sum -= (long long)nums[left];
                left++;
            }
            right++;
        }

        return (right - left);
    }
};
