// Link: https://leetcode.com/problems/magnetic-force-between-two-balls

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: magnetic-force-between-two-balls
 *  RUNTIME: 233 ms
 *  MEMORY: 57.9 MB
 *  DATE: 3-9-2023, 11:26:06 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int countBalls(int force, vector<int> &pos) {
        int i = 0, n = pos.size(), count = 1;
        for(int j=1; j<n; j++) {
            if(pos[j] - pos[i] >= force) {
                count++;
                i = j;
            }
        }
        return count;
    }
    int maxDistance(vector<int>& pos, int balls) {
        sort(pos.begin(), pos.end());
        int n = pos.size(), ans = 0;
        int low = 0;
        int high= pos[n-1] - pos[0];

        while(low <= high) {
            int mid = (low+high)/2;
            if(countBalls(mid, pos) < balls) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};
