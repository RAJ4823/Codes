// Link: https://leetcode.com/problems/jump-game-vii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game-vii
 *  RUNTIME: 52 ms
 *  MEMORY: 20.2 MB
 *  DATE: 2-8-2023, 10:40:58 AM
 *
 */

// Solution:

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] == '1') return false;

        queue<int> q;
        q.push(0);
        int prevIndex = -1;

        while(!q.empty()) {
            int index = q.front();
            q.pop();
            
            int start = max(index + minJump, prevIndex);
            int end = min(index + maxJump, n - 1);
            for(int j = start; j <= end; j++) {
                if(j == n-1)        return true;
                if(s[j] == '0')     q.push(j);
            }
            prevIndex = min(end + 1, n);
        }
        return false;
    }
};
