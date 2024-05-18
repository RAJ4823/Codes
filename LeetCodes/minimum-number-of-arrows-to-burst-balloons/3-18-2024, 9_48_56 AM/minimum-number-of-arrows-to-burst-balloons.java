// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-arrows-to-burst-balloons
 *  RUNTIME: 54 ms
 *  MEMORY: 68.9 MB
 *  DATE: 3-18-2024, 9:48:56 AM
 *
 */

// Solution:

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b)-> {
            if(a[0] == b[0]) 
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        int count = 1;
        long prevEnd = points[0][1];
        for(int[] arr: points) {
            if(arr[0] <= prevEnd) {
                if(arr[1] < prevEnd) {
                    prevEnd = arr[1];
                }
            } else {
                prevEnd = arr[1];
                count++;
            }
        }
        return count;
    }
}
