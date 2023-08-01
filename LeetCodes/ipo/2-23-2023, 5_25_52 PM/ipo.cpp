// Link: https://leetcode.com/problems/ipo

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: ipo
 *  RUNTIME: 234 ms
 *  MEMORY: 82 MB
 *  DATE: 2-23-2023, 5:25:52 PM
 *
 */

// Solution:

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pc;
        int n = profits.size();
        for(int i=0; i<n; i++) 
            pc.push_back({capital[i], profits[i]});
        sort(pc.begin(), pc.end());

        priority_queue<int> pq;
        int j = 0;
        for (int i = 0; i < k; i++) {
            while (j < n && pc[j].first <= w) {
                pq.push(pc[j].second);
                j++;
            }
            if (pq.empty()) 
                return w;
                
            w += pq.top();
            pq.pop();
        }
        return w;
        
    }
};
