// Link: https://leetcode.com/problems/stone-game-vi

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-vi
 *  RUNTIME: 387 ms
 *  MEMORY: 113.7 MB
 *  DATE: 5-26-2023, 12:30:32 PM
 *
 */

// Solution:

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int,int>> pq;

        for(int i=0; i<a.size(); i++) {
            pq.push({a[i] + b[i], i});
        }

        int alice = 0, bob = 0;
        bool turn = true;
        while(!pq.empty()) {
            // cout << pq.top().second << ' ';
            if(turn)   alice += a[pq.top().second];
            else       bob   += b[pq.top().second];
            pq.pop();
            turn = !turn;
        }

        if(alice == bob) return 0;
        else if(alice > bob) return 1;
        return -1;
    }
};
