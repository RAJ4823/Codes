// Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: eliminate-maximum-number-of-monsters
 *  RUNTIME: 105 ms
 *  MEMORY: 81.3 MB
 *  DATE: 11-7-2023, 1:07:26 PM
 *
 */

// Solution:

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i=0; i<dist.size(); i++) 
            dist[i] = (dist[i] - 1) / speed[i];
        sort(dist.begin(), dist.end());

        for(int i=0; i<dist.size(); i++) {
            if(i > dist[i])
                return i;
        }
        return dist.size();
    }
};
