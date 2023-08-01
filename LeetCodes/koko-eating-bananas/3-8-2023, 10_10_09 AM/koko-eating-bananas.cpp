// Link: https://leetcode.com/problems/koko-eating-bananas

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: koko-eating-bananas
 *  RUNTIME: 37 ms
 *  MEMORY: 19 MB
 *  DATE: 3-8-2023, 10:10:09 AM
 *
 */

// Solution:

class Solution {
public:
    long long findHours(int k, vector<int> &piles) {
        long long h = 0;
        for(auto &val: piles) {
            h += (val / k);
            if(val % k) ++h;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1, maxK = piles[0];
        for(auto &val: piles) {
            maxK = max(maxK, val);
        }

        while(minK <= maxK) {
            int mid = (maxK + minK)/2;
            if(findHours(mid, piles) > h) minK = mid+1;
            else maxK = mid - 1;
        }
        return minK;
    }
};
