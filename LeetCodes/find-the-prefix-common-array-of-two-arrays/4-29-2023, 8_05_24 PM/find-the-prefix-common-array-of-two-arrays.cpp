// Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-prefix-common-array-of-two-arrays
 *  RUNTIME: 53 ms
 *  MEMORY: 82 MB
 *  DATE: 4-29-2023, 8:05:24 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n);
        vector<int> c1(51, 0), c2(51, 0);
        
        for(int i=0; i<n; i++) {
            c1[a[i]] = 1;
            c2[b[i]] = 1;
            
            int count= 0;
            for(int j=1; j<=50; j++) {
                if(c1[j] > 0 && c2[j] > 0) {
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
