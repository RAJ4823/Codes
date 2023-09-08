// Link: https://leetcode.com/problems/maximum-length-of-pair-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-length-of-pair-chain
 *  RUNTIME: 53 ms
 *  MEMORY: 22.6 MB
 *  DATE: 8-13-2023, 2:45:00 PM
 *
 */

// Solution:

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);

        int ans = 1;
        int tail = pairs[0][1];
        for(int i=1; i<n; i++){
            if(pairs[i][0]>tail){
                ans ++;
                tail = pairs[i][1];
            }
        }

        return ans;

    }
};
