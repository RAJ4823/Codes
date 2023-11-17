// Link: https://leetcode.com/problems/number-of-flowers-in-full-bloom

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-flowers-in-full-bloom
 *  RUNTIME: 228 ms
 *  MEMORY: 82.3 MB
 *  DATE: 10-11-2023, 8:56:25 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end, ans;
        for(auto &flower: flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(auto &index: people) {
            int left = upper_bound(start.begin(), start.end(), index) - start.begin();
            int right = lower_bound(end.begin(), end.end(), index) - end.begin();
            ans.push_back(left - right);
        }
        return ans;
    }
};
