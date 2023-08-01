// Link: https://leetcode.com/problems/queue-reconstruction-by-height

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: queue-reconstruction-by-height
 *  RUNTIME: 56 ms
 *  MEMORY: 11.6 MB
 *  DATE: 6-6-2023, 9:19:07 AM
 *
 */

// Solution:

class Solution {
public: 
    static bool comp(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        int n = people.size();
        vector<vector<int>> ans(n);

        for(int i=0; i<n; i++) {
            int pos = people[i][1], j = 0;
            while(j < n) {
                if(ans[j].empty()) {
                    if(!(pos--)) break;
                }
                j++;
            }
            ans[j] = people[i];
        }
        return ans;
    }
};
