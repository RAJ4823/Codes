// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-hills-and-valleys-in-an-array
 *  RUNTIME: 6 ms
 *  MEMORY: 9.1 MB
 *  DATE: 9-29-2023, 9:59:07 AM
 *
 */

// Solution:

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(!arr.empty() && arr.back() == nums[i]) {
                continue;
            }   
            arr.push_back(nums[i]);
        }

        int count = 0, m = arr.size();
        for(int i=1; i<m-1; i++) {
            if(arr[i-1] > arr[i] && arr[i+1] > arr[i])
                count++;
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i])
                count++;
        }
        return count;
    }
};
