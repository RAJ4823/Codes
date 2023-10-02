// Link: https://leetcode.com/problems/median-of-two-sorted-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: median-of-two-sorted-arrays
 *  RUNTIME: 39 ms
 *  MEMORY: 90 MB
 *  DATE: 9-21-2023, 10:15:49 AM
 *
 */

// Solution:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0, k = 0;

        vector<int> v(n+m);

        while(i < n && j < m) {
            v[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
        }

        while(i < n) {
            v[k++] = a[i++];
        }   

        while(j < m) {
            v[k++] = b[j++];
        }   

        int x = k >> 1;
        if(k & 1) {
            return (double)(v[x]);
        }
        return (double)(v[x] + v[x-1]) / 2;
    }
};
