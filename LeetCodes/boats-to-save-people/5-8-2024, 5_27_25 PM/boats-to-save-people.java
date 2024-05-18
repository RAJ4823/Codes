// Link: https://leetcode.com/problems/boats-to-save-people

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: boats-to-save-people
 *  RUNTIME: 16 ms
 *  MEMORY: 55.1 MB
 *  DATE: 5-8-2024, 5:27:25 PM
 *
 */

// Solution:

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int i=0, j = people.length - 1;
        int boats = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            boats++;
        }
        return boats;
    }
}
