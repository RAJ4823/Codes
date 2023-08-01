// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-bags-with-full-capacity-of-rocks
 *  RUNTIME: 192 ms
 *  MEMORY: 86.8 MB
 *  DATE: 12-27-2022, 4:05:31 PM
 *
 */

// Solution:

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int rem) {
        int n = rocks.size(), count = 0;
        vector<int> diff(n);
        for(int i=0; i<n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        for(int i=0;i<n;i++) {
            rem -= diff[i];
            if(rem < 0)
                break;
            count++;
        }
        return count;
    }
};
