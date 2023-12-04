// Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-amount-of-time-to-collect-garbage
 *  RUNTIME: 168 ms
 *  MEMORY: 102.4 MB
 *  DATE: 11-20-2023, 10:48:15 AM
 *
 */

// Solution:

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0;
        int lastp = 0, lastm = 0, lastg = 0;
        for(int i = 0; i < garbage.size(); ++i){
            for(auto c: garbage[i]){
                count++;
                if(c == 'M') lastm = i;
                else if(c == 'G') lastg = i;
                else lastp = i;
            }
        }
        for(int i = 1; i < travel.size(); ++i){
            travel[i] += travel[i-1];
        }
        int ans = count;
        if(lastm > 0) ans+= travel[lastm-1];
        if(lastg > 0) ans+= travel[lastg-1];
        if(lastp > 0) ans+= travel[lastp-1];
        return ans;
    }
};
