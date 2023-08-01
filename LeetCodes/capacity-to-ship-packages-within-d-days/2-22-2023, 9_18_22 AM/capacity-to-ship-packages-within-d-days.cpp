// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: capacity-to-ship-packages-within-d-days
 *  RUNTIME: 1353 ms
 *  MEMORY: 26.2 MB
 *  DATE: 2-22-2023, 9:18:22 AM
 *
 */

// Solution:

class Solution {
public:
    bool possible(int w, int days, vector<int>& weights) {
        int count = 1, curr = 0;
        for (int weight : weights) {
            curr += weight;
            if (curr > w) {
                count++;
                curr = weight;
            }
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), maxWeight = 0;
        for(int i=0; i<n; i++) {
            maxWeight = max(maxWeight, weights[i]);
        }

        int w = maxWeight;
        while(!possible(w, days, weights)) {
            w++;
        }
        return w;
    }
};
