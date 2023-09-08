// Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-taps-to-open-to-water-a-garden
 *  RUNTIME: 4 ms
 *  MEMORY: 14.6 MB
 *  DATE: 8-31-2023, 9:20:41 AM
 *
 */

// Solution:

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxEnd(n+1, 0);
        for(int i=0; i<=n; i++) {
            int start = max(0, i - ranges[i]);
            int end = i + ranges[i];
            maxEnd[start] = end;
        }

        int taps = 0, currEnd = 0, nextEnd = 0;
        for(int i=0; i<=n; i++) {
            if(i > nextEnd) return -1;
            if(i > currEnd) {
                currEnd = nextEnd;
                taps++;
            }
            nextEnd = max(nextEnd, maxEnd[i]);
        }
        return taps;
    }
};
