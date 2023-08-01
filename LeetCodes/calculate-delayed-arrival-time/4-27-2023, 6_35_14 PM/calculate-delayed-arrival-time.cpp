// Link: https://leetcode.com/problems/calculate-delayed-arrival-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: calculate-delayed-arrival-time
 *  RUNTIME: 5 ms
 *  MEMORY: 6 MB
 *  DATE: 4-27-2023, 6:35:14 PM
 *
 */

// Solution:

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
