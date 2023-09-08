// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-penalty-for-a-shop
 *  RUNTIME: 37 ms
 *  MEMORY: 18.9 MB
 *  DATE: 8-29-2023, 9:32:16 AM
 *
 */

// Solution:

class Solution {
public:
    int bestClosingTime(string arr) {
        int n = arr.size();
        vector<int> countY(n+1, 0), countN(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            countY[i] =  countY[i+1] + (arr[i] == 'Y');
        }
        for(int i=1; i<=n; i++) {
            countN[i] = countN[i-1] + (arr[i-1] == 'N');
        }

        int ans = n, mini = n;
        for(int i=0; i<=n; i++) {
            if(countY[i] + countN[i] < mini) {
                mini = countY[i] + countN[i];
                ans = i;
            }
        }
        return ans;
    }
};
