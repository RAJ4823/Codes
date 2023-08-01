// Link: https://leetcode.com/problems/single-threaded-cpu

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: single-threaded-cpu
 *  RUNTIME: 520 ms
 *  MEMORY: 120 MB
 *  DATE: 12-29-2022, 4:05:15 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int n = tasks.size();
        vector<array<int, 3>> arr(n);
        vector<int> ans;

        for(int i=0; i<n; i++) {
            arr[i] = {tasks[i][0], tasks[i][1], i};
        }
        sort(arr.begin(), arr.end());

        long long int i = 0, time = 0;
        while(i < n || !pq.empty()) {
            if(pq.empty() && time < arr[i][0])
                time = arr[i][0];

            while(i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            long long int task = pq.top().second;
            long long int processTime = pq.top().first;
            pq.pop();

            time += processTime;
            ans.push_back(task);
        }
        return ans;
    }
};
