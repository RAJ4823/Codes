// Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: convert-an-array-into-a-2d-array-with-conditions
 *  RUNTIME: 11 ms
 *  MEMORY: 30 MB
 *  DATE: 4-2-2023, 8:19:17 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> m;
        
        for(auto &val: nums) {
            m[val]++;
        }
        
        int size = m.size();
        while(size > 0) {
            vector<int> temp;
            size = m.size();
            for(auto &x: m) {
                if(x.second > 0) {
                    temp.push_back(x.first);
                    x.second--;
                } else {
                    size--;
                }
            }  
            if(size > 0)
                ans.push_back(temp);
        }
        return ans;
    }
};
