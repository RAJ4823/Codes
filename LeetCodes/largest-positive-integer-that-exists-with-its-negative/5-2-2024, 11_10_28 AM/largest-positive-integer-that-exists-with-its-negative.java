// Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-positive-integer-that-exists-with-its-negative
 *  RUNTIME: 9 ms
 *  MEMORY: 45.1 MB
 *  DATE: 5-2-2024, 11:10:28 AM
 *
 */

// Solution:

class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> st = new HashSet<>();
        int max = Integer.MIN_VALUE;
        Arrays.sort(nums);
        for(int num: nums) {
            st.add(num);
            if(num > max && st.contains(-num)) {
                max = num;
            }
        }
        return max == Integer.MIN_VALUE ? -1 : max;
    }
}
