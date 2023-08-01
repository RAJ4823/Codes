// Link: https://leetcode.com/problems/median-of-two-sorted-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: median-of-two-sorted-arrays
 *  RUNTIME: 46 ms
 *  MEMORY: 89.6 MB
 *  DATE: 12-22-2022, 5:50:52 PM
 *
 */

// Solution:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        double med = 0.0;
        int n = a.size(), i = 0;
        int m = b.size(), j = 0;
        vector<int> v(n+m);
        int k = 0;
        while(i < n && j < m) {
            v[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
        }
        while(i < n)    v[k++] = a[i++];
        while(j < m)    v[k++] = b[j++];
        int x = k/2;
        if(k%2 == 0) {
            med = (double)(v[x] + v[x-1])/2;
        } else {
            med = (double)(v[x]);
        }
        return med;
    }
};
