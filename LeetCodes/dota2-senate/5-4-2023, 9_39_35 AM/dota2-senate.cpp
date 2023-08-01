// Link: https://leetcode.com/problems/dota2-senate

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: dota2-senate
 *  RUNTIME: 3 ms
 *  MEMORY: 8.1 MB
 *  DATE: 5-4-2023, 9:39:35 AM
 *
 */

// Solution:

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        int n = senate.size();
        
        for(int i=0; i<n; i++) {
            if(senate[i] == 'R') {
                rq.push(i); 
            } else {
                dq.push(i);
            }
        }
        
        int a, b;
        while(!rq.empty() and !dq.empty()){
            a = rq.front();
            b = dq.front();
            rq.pop();
            dq.pop();
            if (a < b)
                rq.push(a+n);
            else
                dq.push(b+n);
        }
        
		if (rq.size() > dq.size())
			return "Radiant";
		return "Dire";
    }
};
