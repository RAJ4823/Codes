// Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-colored-pieces-if-both-neighbors-are-the-same-color
 *  RUNTIME: 37 ms
 *  MEMORY: 13.8 MB
 *  DATE: 10-2-2023, 11:38:33 AM
 *
 */

// Solution:

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0, A = 0, B = 0;
        for(auto &ch: colors) {
            if(ch == 'A') {
                A++;
                bob += max(0, B - 2);
                B = 0;
            } else {
                B++;
                alice += max(0, A - 2);
                A = 0;
            }
        }

        alice += max(0, A - 2);
        bob += max(0, B - 2);

        return (alice > 0) && (alice > bob);
    }
};
