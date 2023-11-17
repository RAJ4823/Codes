// Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pairs-of-songs-with-total-durations-divisible-by-60
 *  RUNTIME: 19 ms
 *  MEMORY: 28.6 MB
 *  DATE: 11-17-2023, 12:12:03 PM
 *
 */

// Solution:

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long long n = time.size(), ans = 0;
        unordered_map<int, long long> count;
        for(auto &x: time) {
            count[x % 60]++;
        }

        for(int i=1; i<30; i++) {
            ans += (count[i] * count[60 - i]);
        }
        ans += (count[0] * (count[0] - 1)) / 2;
        ans += (count[30] * (count[30] - 1)) / 2;
        return ans;
    }
};
