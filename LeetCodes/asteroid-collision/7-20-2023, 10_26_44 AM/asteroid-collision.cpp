// Link: https://leetcode.com/problems/asteroid-collision

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: asteroid-collision
 *  RUNTIME: 20 ms
 *  MEMORY: 17.4 MB
 *  DATE: 7-20-2023, 10:26:44 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(!ans.empty() && arr[i] < 0){
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i]))
                    ans.pop_back();
                if(!ans.empty() && ans.back() == abs(arr[i]))
                    ans.pop_back();
                else if(ans.empty() || ans.back() < 0) 
                    ans.push_back(arr[i]);
            } else {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
