// Link: https://leetcode.com/problems/total-cost-to-hire-k-workers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: total-cost-to-hire-k-workers
 *  RUNTIME: 198 ms
 *  MEMORY: 71.7 MB
 *  DATE: 6-26-2023, 5:12:28 PM
 *
 */

// Solution:

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        int i = 0, j = n-1;
        long long cost = 0;
        
        if(n <= c*2) {
            sort(costs.begin(), costs.end());
            for(int i=0; i<k; i++) cost += (long long)(costs[i]);
            return cost;
        }
        
        priority_queue<int> ql, qr, pq;

        for(i;i<c;i++)      ql.push(-costs[i]);
        for(j;j>n-c-1;j--)  qr.push(-costs[j]);
 
        while(i <= j && k > 0) {
            if(ql.top() >= qr.top()) {
                cost += ql.top();
                ql.pop();
                ql.push(-costs[i]);
                i++;
            } else {
                cost += qr.top();
                qr.pop();
                qr.push(-costs[j]);
                j--;
            }
            k--;
        }

        while(!ql.empty()) pq.push(ql.top()), ql.pop();
        while(!qr.empty()) pq.push(qr.top()), qr.pop();

        while(k > 0) {
            cost += pq.top();
            pq.pop();
            k--;
        }
        return -cost;
    }
};
