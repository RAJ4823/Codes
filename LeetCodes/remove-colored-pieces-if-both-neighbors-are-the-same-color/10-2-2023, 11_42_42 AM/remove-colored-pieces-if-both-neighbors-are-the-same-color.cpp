// Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-colored-pieces-if-both-neighbors-are-the-same-color
 *  RUNTIME: 31 ms
 *  MEMORY: 13.9 MB
 *  DATE: 10-2-2023, 11:42:42 AM
 *
 */

// Solution:

class Solution {
public:
    bool winnerOfGame(string str) {
        int player[2] = {0};
        for(int i=1; i < str.size() - 1; i++) {
            if(str[i-1] == str[i] && str[i] == str[i+1]) {
                player[str[i] - 'A']++;
            }
        }
        return player[0] > player[1];
    }
};
