// Link: https://leetcode.com/problems/beautiful-towers-i

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: beautiful-towers-i
 *  RUNTIME: 45 ms
 *  MEMORY: 24 MB
 *  DATE: 9-26-2023, 5:15:20 PM
 *
 */

// Solution:

class Solution {
public:
    long long find(int index, vector<int> &arr) {
        int n = arr.size();
        int i = index - 1, j = index + 1;

        long long sum = arr[index], mini = arr[index];
        while(i >= 0) {
            mini = min(mini, (long long)arr[i--]);
            sum += mini;
        }
        mini = arr[index];
        while(j < n) {
            mini = min(mini, (long long)arr[j++]);
            sum += mini;
        }
        return sum;
    }
    long long maximumSumOfHeights(vector<int>& arr) {
        long long ans = 0;
        
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            ans = max(ans, find(i, arr));
        }
        return ans;
    }
};
