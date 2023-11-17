// Link: https://leetcode.com/problems/build-an-array-with-stack-operations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: build-an-array-with-stack-operations
 *  RUNTIME: 4 ms
 *  MEMORY: 8.1 MB
 *  DATE: 11-3-2023, 4:53:09 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr = 0;
        for(auto &val: target) {
            while(curr < val) {
                ans.push_back("Push");
                curr++;
                if(curr != val)
                    ans.push_back("Pop");
            }
        }
        return ans;
    }
};
