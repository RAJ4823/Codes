// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: peak-index-in-a-mountain-array
 *  RUNTIME: 114 ms
 *  MEMORY: 59.6 MB
 *  DATE: 7-25-2023, 10:29:47 PM
 *
 */

// Solution:

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,m,h=arr.size()-1;
        int ans=-1;
        while(l<=h){
            m=l+(h-l)/2;
            if(arr[m]>arr[m+1]){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};
