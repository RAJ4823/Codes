// Link: https://leetcode.com/problems/total-cost-to-hire-k-workers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: total-cost-to-hire-k-workers
 *  RUNTIME: 217 ms
 *  MEMORY: 73.9 MB
 *  DATE: 6-26-2023, 5:19:45 PM
 *
 */

// Solution:

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        int i = 0, j = n-1;
        long long cost = 0;
        priority_queue<int> ql, qr, pq;
        
        if(n <= c*2) {
            for(int i=0; i<n; i++) 
                pq.push(-costs[i]);            
        }
        else {
            for(i; i < c; i++)      
                ql.push(-costs[i]);
            for(j; j > n-c-1; j--)  
                qr.push(-costs[j]);
    
            while(i <= j && k > 0) {
                if(ql.top() >= qr.top())
                    cost += ql.top(), ql.pop(), ql.push(-costs[i++]);
                else
                    cost += qr.top(), qr.pop(), qr.push(-costs[j--]);
                k--;
            }

            while(!ql.empty()) 
                pq.push(ql.top()), ql.pop();
            while(!qr.empty()) 
                pq.push(qr.top()), qr.pop();
        }

        while(k > 0)
            cost += pq.top(), pq.pop(), k--;
        
        return -cost;
    }
};
