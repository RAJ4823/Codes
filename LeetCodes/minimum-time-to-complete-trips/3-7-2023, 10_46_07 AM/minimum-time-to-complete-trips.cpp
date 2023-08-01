// Link: https://leetcode.com/problems/minimum-time-to-complete-trips

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-to-complete-trips
 *  RUNTIME: 345 ms
 *  MEMORY: 94.5 MB
 *  DATE: 3-7-2023, 10:46:07 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long findTrips(ll givenTime, vector<int> &time) {
        ll trips = 0;
        for(auto &t: time) {
            ll value = t;
            if(value > givenTime) break;
            trips += (givenTime / value);
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        ll maxTime = (ll)time[0] * (ll)totalTrips;
        ll minTime = 1;

        while(minTime < maxTime) {
            ll midTime = minTime + (maxTime - minTime) / 2;
            ll trips = findTrips(midTime, time); 

            if(trips >= totalTrips) maxTime = midTime;
            else minTime = midTime + 1;
        } 
        return minTime;
    }
};
