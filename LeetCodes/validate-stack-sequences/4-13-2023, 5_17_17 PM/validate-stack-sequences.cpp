// Link: https://leetcode.com/problems/validate-stack-sequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: validate-stack-sequences
 *  RUNTIME: 11 ms
 *  MEMORY: 15.4 MB
 *  DATE: 4-13-2023, 5:17:17 PM
 *
 */

// Solution:

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, j = 0;
        int n = pushed.size();

        while(i < n) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
};
