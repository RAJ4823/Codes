// Link: https://leetcode.com/problems/guess-number-higher-or-lower

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: guess-number-higher-or-lower
 *  RUNTIME: 2 ms
 *  MEMORY: 6.2 MB
 *  DATE: 10-10-2023, 1:30:26 PM
 *
 */

// Solution:

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#define ll long long
class Solution {
public:
    int guessNumber(int n) {
        ll low = 1, high = (ll)n;
        while(low <= high) {
            ll mid = (low + high) / 2;
            int val = guess(mid);
            if(val == 0)
                return mid;
            else if(val == -1)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
};
