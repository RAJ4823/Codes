// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: capacity-to-ship-packages-within-d-days
 *  RUNTIME: 42 ms
 *  MEMORY: 26.2 MB
 *  DATE: 2-22-2023, 9:20:48 AM
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
        int n = weights.size(), maxWeight = 0, totalWeight = 0;
        for(int i=0; i<n; i++) {
            maxWeight = max(maxWeight, weights[i]);
            totalWeight += weights[i];
        }

        int mini = maxWeight, maxi = totalWeight;
        while(mini < maxi) {
            int mid = (mini + maxi) / 2;
            if(possible(mid, days, weights)) {
                maxi = mid;
            } else {
                mini = mid + 1;
            }
        }
        return mini;
    }
};
