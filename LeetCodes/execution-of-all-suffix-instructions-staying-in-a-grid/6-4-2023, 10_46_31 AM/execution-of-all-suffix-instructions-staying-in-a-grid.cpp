// Link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: execution-of-all-suffix-instructions-staying-in-a-grid
 *  RUNTIME: 36 ms
 *  MEMORY: 10 MB
 *  DATE: 6-4-2023, 10:46:31 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, string &moves, int row, int col, int n) {
        int steps = 0;
        while(i < moves.size()) {
            switch(moves[i]) {
                case 'R': col++; break;
                case 'L': col--; break;
                case 'U': row--; break;
                case 'D': row++; break;
                default: break;
            }
            if(row < 0 || col < 0 || row >= n || col >= n)
                return steps;
            steps++;
            i++;
        }
        return steps;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++) {
            ans[i] = find(i, s, startPos[0], startPos[1], n);
        }
        return ans;
    }
};
