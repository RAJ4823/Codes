// Link: https://leetcode.com/problems/minimize-deviation-in-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimize-deviation-in-array
 *  RUNTIME: 556 ms
 *  MEMORY: 56.8 MB
 *  DATE: 2-24-2023, 8:58:11 PM
 *
 */

// Solution:

class Solution {
public:
   int minimumDeviation(vector<int>& nums) {
    int ans = INT_MAX, mini = INT_MAX;
    priority_queue<int> pq;

    for (auto n : nums) {
        if(n % 2) n *= 2;
        pq.push(n);
        mini = min(mini, n); 
    }

    while (pq.top() % 2 == 0) {
        int m = pq.top() / 2;
        ans = min(ans, pq.top() - mini);
        mini = min(mini, m);
        pq.push(m);
        pq.pop();
    }
    return min(ans, pq.top() - mini);
}
};
