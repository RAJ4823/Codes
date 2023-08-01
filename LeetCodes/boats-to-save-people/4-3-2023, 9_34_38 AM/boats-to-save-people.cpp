// Link: https://leetcode.com/problems/boats-to-save-people

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: boats-to-save-people
 *  RUNTIME: 79 ms
 *  MEMORY: 42 MB
 *  DATE: 4-3-2023, 9:34:38 AM
 *
 */

// Solution:

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int boats = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) i++, j--;
            else j--;
            boats++;
        }
        return boats;
    }
};
