// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-operations-to-move-all-balls-to-each-box
 *  RUNTIME: 148 ms
 *  MEMORY: 9.4 MB
 *  DATE: 4-18-2023, 9:21:07 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.size();
        for(int i=0; i<n; i++) {
            int steps = 0, count = 0;
            for(int j=i; j>=0; j--) {
                if(boxes[j] == '1') count += steps;
                steps++;
            }
            steps = 0;
            for(int j=i; j<n; j++) {
                if(boxes[j] == '1') count += steps;
                steps++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
