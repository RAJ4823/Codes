// Link: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-ways-to-group-overlapping-ranges
 *  RUNTIME: 413 ms
 *  MEMORY: 89.3 MB
 *  DATE: 3-28-2023, 9:46:19 PM
 *
 */

// Solution:

class Solution {
public:
    long long MOD = 1e9 + 7;
    long long pow(int a, int b){
        long long x=1, y=a; 
        while (b > 0) {
            if (b%2 == 1) {
                x = (x*y) % MOD;
            }
            y = (y*y) % MOD;
            b /= 2;
        }
        return x % MOD;
    }
 
    
    bool static comp(const vector<int> &temp1, const vector<int> &temp2) {
        if(temp1[0] == temp2[0])
            return temp1[1] < temp2[1];
        return temp1[0] < temp2[0];
    }
    
    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>> merged;
        int n = ranges.size();
        sort(ranges.begin(), ranges.end(), comp);
        
        //DEBUG
        // for(int i=0; i<n; i++) {
        //     cout << ranges[i][0] << ' ' << ranges[i][1] << endl;
        // }
        // cout << endl;
        
        merged.push_back(ranges[0]);
        for(int i=1; i<n; i++) {
            if(merged.back()[1] >= ranges[i][0]) {
                merged.back()[1] = max(merged.back()[1], ranges[i][1]);
            } else {
                merged.push_back(ranges[i]);
            }
        }
        
        long long N = merged.size();
        return pow(2, N);
    }
};
