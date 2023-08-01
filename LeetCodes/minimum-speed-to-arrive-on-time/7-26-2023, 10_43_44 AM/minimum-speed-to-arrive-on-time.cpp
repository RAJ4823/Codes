// Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-speed-to-arrive-on-time
 *  RUNTIME: 379 ms
 *  MEMORY: 101.3 MB
 *  DATE: 7-26-2023, 10:43:44 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0;
    double findHours(int speed, vector<int> &dist) {
        double hours = 0.0;
        for(int i=0; i<n-1; i++) {
            int time = (dist[i] + speed - 1)/speed;
            hours += (double)time;
        }
        hours += ((double)dist[n-1] / (double)speed);
        return hours;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        n = dist.size();
        int low = 1, high = 100000007;
        int ans = high;
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(findHours(mid, dist) <= hour) {
                ans = min(mid, ans);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(ans == 100000007) return -1;
        return ans;
    }
};
