// Link: https://leetcode.com/problems/find-the-winner-of-an-array-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-winner-of-an-array-game
 *  RUNTIME: 84 ms
 *  MEMORY: 63.4 MB
 *  DATE: 11-5-2023, 6:17:06 PM
 *
 */

// Solution:

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size())
            return *max_element(arr.begin(), arr.end());
            
        int winner = arr[0], count = 0;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > winner) {
                winner = arr[i];
                count = 1;
            } else {
                count++;
            }
            if(count == k)
                return winner;
        }
        return winner;
    }
};
