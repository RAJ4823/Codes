// Link: https://leetcode.com/problems/sort-the-jumbled-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-the-jumbled-numbers
 *  RUNTIME: 711 ms
 *  MEMORY: 131.8 MB
 *  DATE: 12-23-2022, 8:03:35 PM
 *
 */

// Solution:

class Solution {
private:
    int decode(int num, vector<int> &mp) {
        int val = 0, mul=1;
        if(num == 0) return mp[0];
        while(num > 0) {
            int dig = num%10;
            num/=10;
            val += (mul*mp[dig]);
            mul*=10;
        }
        return val;
    }
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        vector<int> v;

        for(auto &num : nums) 
        {
            int val = decode(num, mp);
            m[val].push_back(num);
        }
        for(auto &i : m)  v.push_back(i.first);
        sort(v.begin(), v.end());
        
        vector<int> ans;
        for(auto &val : v) {
            for(auto &num : m[val]) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
