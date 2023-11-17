// Link: https://leetcode.com/problems/number-of-good-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-good-pairs
 *  RUNTIME: 0 ms
 *  MEMORY: 7.6 MB
 *  DATE: 10-3-2023, 1:49:52 PM
 *
 */

// Solution:

class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int &x: A) ans += cnt[x]++;
        
        return ans;
    }
};
