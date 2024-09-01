// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-k-th-smallest-pair-distance
 *  RUNTIME: 8 ms
 *  MEMORY: 44.8 MB
 *  DATE: 8-14-2024, 11:21:59 AM
 *
 */

// Solution:


public class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        
        int left = 0;
        int right = nums[nums.length - 1] - nums[0];
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (issmallpairs(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    private boolean issmallpairs(int[] nums, int k, int mid) {
        int count = 0, left = 0;
        for (int right = 1; right < nums.length; right++) {
            while (nums[right] - nums[left] > mid) left++;
            count += right - left;
        }
        return (count >= k);
    }
}
