// Link: https://leetcode.com/problems/jewels-and-stones

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jewels-and-stones
 *  RUNTIME: 3 ms
 *  MEMORY: 6.1 MB
 *  DATE: 9-13-2023, 9:05:39 AM
 *
 */

// Solution:

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int arr[52] = {0};
        for(auto &ch: jewels) {
            if(ch >= 'a' && ch <= 'z') {
                arr[ch - 'a'] = 1;
            } else {
                arr[ch - 'A' + 26] = 1; 
            }
        }
        int ans = 0;
        for(auto &ch: stones) {
            if(ch >= 'a' && ch <= 'z') {
                ans += arr[ch - 'a'];
            } else {
                ans += arr[ch - 'A' + 26];
            }
        }
        return ans;
    }
};
