// Link: https://leetcode.com/problems/maximum-ice-cream-bars

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-ice-cream-bars
 *  RUNTIME: 576 ms
 *  MEMORY: 76.5 MB
 *  DATE: 1-6-2023, 4:54:42 PM
 *
 */

// Solution:

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0, count = 0;
        for(auto &price:costs) {
            if(sum + price <= coins) {
                sum += price;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
