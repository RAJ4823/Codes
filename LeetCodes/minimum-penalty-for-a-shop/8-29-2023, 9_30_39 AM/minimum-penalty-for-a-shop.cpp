// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-penalty-for-a-shop
 *  RUNTIME: 44 ms
 *  MEMORY: 18.8 MB
 *  DATE: 8-29-2023, 9:30:39 AM
 *
 */

// Solution:

class Solution {
public:
    int bestClosingTime(string arr) {
        int n = arr.size();
        vector<int> countY(n+1, 0), countN(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            if(arr[i] == 'Y') {
                countY[i] = countY[i+1] + 1;
            } else {
                countY[i] = countY[i+1];
            }
        }
        for(int i=1; i<=n; i++) {
            if(arr[i-1] == 'N') {
                countN[i] = countN[i-1] + 1;
            } else {
                countN[i] = countN[i-1];
            }
        }

        int ans = n, mini = n;
        for(int i=0; i<=n; i++) {
            int sum = countY[i] + countN[i];
            if(sum < mini) {
                mini = sum;
                ans = i;
            }
        }
        return ans;
    }
};
