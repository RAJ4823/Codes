// Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: group-the-people-given-the-group-size-they-belong-to
 *  RUNTIME: 3 ms
 *  MEMORY: 14.2 MB
 *  DATE: 9-11-2023, 9:30:04 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]) != mp.end() && mp[arr[i]].size() == arr[i]) {
                ans.push_back(mp[arr[i]]);
                mp.erase(arr[i]);
            }
            mp[arr[i]].push_back(i);
        }
        for(auto &x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
