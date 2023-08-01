// Link: https://leetcode.com/problems/jump-game-iv

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game-iv
 *  RUNTIME: 270 ms
 *  MEMORY: 99.2 MB
 *  DATE: 3-5-2023, 9:35:02 AM
 *
 */

// Solution:

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> pos;
        for(int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        } 
        queue<pair<int,int>> q;
        vector<int> minSteps(n, INT_MAX);
        q.push({0, 0});
        minSteps[0] = 0;
        while(!q.empty()) {
            int index = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(index == n-1) 
                break;

            for(auto &next: pos[arr[index]]) {
                if(steps + 1 < minSteps[next]) {
                    minSteps[next] = steps + 1;
                    q.push({next, steps + 1});
                }
            }
            pos.erase(arr[index]);
            if(index+1 < n && steps + 1 < minSteps[index+1]) {
                minSteps[index+1] = steps+1;
                q.push({index+1, steps + 1});
            }
            if(index-1>= 0 && steps + 1 < minSteps[index-1]) {
                minSteps[index-1] = steps+1;
                q.push({index-1, steps + 1});
            }
        } 
        return minSteps[n-1];
    }
};
