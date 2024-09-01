// Link: https://leetcode.com/problems/average-waiting-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: average-waiting-time
 *  RUNTIME: 4 ms
 *  MEMORY: 72.7 MB
 *  DATE: 7-9-2024, 11:45:40 AM
 *
 */

// Solution:

class Solution {
    public double averageWaitingTime(int[][] customers) {
        long waiting_time = 0;
        long last_prepared_time = customers[0][0];
        for(int[] customer: customers) {
            long arriving_time = customer[0];
            long start_time = Math.max(last_prepared_time, arriving_time);
            long preparing_time = start_time + customer[1];

            waiting_time += preparing_time - arriving_time;
            last_prepared_time = preparing_time;
        }
        long total_customers = customers.length;
        double average_waiting_time = ((double) waiting_time / total_customers);
        return average_waiting_time;
    }
}
