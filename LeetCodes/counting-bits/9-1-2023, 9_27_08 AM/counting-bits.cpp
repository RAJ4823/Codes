// Link: https://leetcode.com/problems/counting-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: counting-bits
 *  RUNTIME: 2 ms
 *  MEMORY: 8.6 MB
 *  DATE: 9-1-2023, 9:27:08 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++) {
            int count = 0, num = i;
            while(num) {
                count += (num & 1);
                num >>= 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
